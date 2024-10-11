"""
Purpose
Perform various operations on S3 buckets using Python boto3
"""


import logging
import sys

import boto3
from botocore.exceptions import ClientError

logger = logging.getLogger(__name__)


class ObjectWrapper:
    """Encapsulates S3 object actions."""

    def __init__(self, s3_object):
        """
        :param s3_object: A Boto3 Object resource. This is a high-level resource in Boto3
                          that wraps object actions in a class-like structure.
        """
        self.object = s3_object
        self.key = self.object.key

    def get(self):
        """
        Gets the object.

        :return: The object data in bytes.
        """
        try:
            body = self.object.get()["Body"].read()
            logger.info(
                "Objects in bucket '%s' are:\n'%s'.",
                self.object.bucket_name,
                self.object.key,)
        except ClientError:
            logger.exception(
                "Couldn't get object '%s' from bucket '%s'.",
                self.object.key,
                self.object.bucket_name,)
            raise
        else:
            return body

    @staticmethod
    def list(bucket, prefix=None):
        """
        Lists the objects in a bucket, optionally filtered by a prefix.

        :param bucket: The bucket to query. This is a Boto3 Bucket resource.
        :param prefix: When specified, only objects that start with this prefix are listed.
        :return: The list of objects.
        """
        try:
            if not prefix:
                objects = list(bucket.objects.all())
            else:
                objects = list(bucket.objects.filter(Prefix=prefix))
            logger.info("Objects in bucket '%s' are:\n'%s'.", bucket.name, [o.key for o in objects])
        except ClientError:
            logger.exception("Couldn't get objects for bucket '%s'.", bucket.name)
            raise
        else:
            return objects

    @staticmethod
    def download_files(bucket, files_list):
        for file in files_list:
            import os
            download_path = f"/tmp/{os.path.basename(file.key)}"
            bucket.Object(file.key).download_file(download_path)
            print(f"Downloaded file {download_path}")

    def copy(self, dest_object):
        """
        Copies the object to another bucket.

        :param dest_object: The destination object initialized with a bucket and key.
                            This is a Boto3 Object resource.
        """
        try:
            dest_object.copy_from(CopySource={"Bucket": self.object.bucket_name, "Key": self.object.key})
            dest_object.wait_until_exists()
            logger.info(
                "Copied object from %s:%s to %s:%s.",
                self.object.bucket_name,
                self.object.key,
                dest_object.bucket_name,
                dest_object.key,)
        except ClientError:
            logger.exception(
                "Couldn't copy object from %s/%s to %s/%s.",
                self.object.bucket_name,
                self.object.key,
                dest_object.bucket_name,
                dest_object.key,)
            raise

def usage_demo():
    print("-" * 88)
    print("OPERATIONS ON S3 OBJECTS using Python boto3 library")
    print("-" * 88)

    logging.basicConfig(level=logging.INFO, format="%(levelname)s: %(message)s")

    if len(sys.argv) < 3:
        raise Exception("ERROR: Please provide S3 bucket_name and prefix")
    bucket_name     = sys.argv[1]
    prefix          = sys.argv[2]
    
    should_download = False
    if len(sys.argv) > 3:
        should_download = sys.argv[3]

    s3_resource = boto3.resource("s3")
    bucket = s3_resource.Bucket(bucket_name)
    print(f"\n\nCreated an object to access bucket: {bucket_name}, prefix: {prefix}\n\n")

    files = ObjectWrapper.list(bucket, prefix)
    print(f"\n\nTheir keys are: \n{', '.join(f.key for f in files)}")

    if should_download:
        print("\n\nDownloading all the files...")
        ObjectWrapper.download_files(bucket, files)

    print("\n\nEND")
    print("-" * 88)


if __name__ == "__main__":
    usage_demo()