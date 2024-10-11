## How to build and run the code in this directory?
- This dir contains files that deal with various AWS services.
- **Example:** `$ python3 s3_bucket_operations.py <S3_BUCKET_NAME> <DIRECTORY_PREFIX> True`
- **Sample output:**
```
----------------------------------------------------------------------------------------
OPERATIONS ON S3 OBJECTS using Python boto3 library
----------------------------------------------------------------------------------------
INFO: Found credentials in shared credentials file: ~/.aws/credentials


Created an object to access bucket: <S3_BUCKET_NAME>, prefix: <DIRECTORY_PREFIX>


INFO: Objects in bucket '<S3_BUCKET_NAME>' are:
'['<DIRECTORY_PREFIX>/object_33_0_1.csv', '<DIRECTORY_PREFIX>/object_33_2_1.csv', '<DIRECTORY_PREFIX>/object_33_4_1.csv', '<DIRECTORY_PREFIX>/object_33_5_1.csv']'.


Their keys are:
<DIRECTORY_PREFIX>/object_33_0_1.csv, <DIRECTORY_PREFIX>/object_33_2_1.csv, <DIRECTORY_PREFIX>/object_33_4_1.csv, <DIRECTORY_PREFIX>/object_33_5_1.csv

Downloading all the files...
Downloaded file /tmp/object_33_0_1.csv
Downloaded file /tmp/object_33_2_1.csv
Downloaded file /tmp/object_33_4_1.csv
Downloaded file /tmp/object_33_5_1.csv

END
----------------------------------------------------------------------------------------
```
