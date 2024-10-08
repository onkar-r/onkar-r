#include <iostream>
#include <iterator>
#include <regex>
#include <string>


void test_regex_search(const std::string& regexStr, const std::string& filename)
{
    std::regex regexPtn(regexStr);
    std::cout << "\n\n=== regex_search with pattern: " << regexStr << ", filename: " << filename << " ===\n";
    if(std::regex_search(filename, regexPtn)) {
        std::cout << "Regex Matched!\n";
    } else {
        std::cout << "Regex didn't match!\n";
    }
    return;
}
 
int main()
{
    std::string s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";
 
    std::regex self_regex("REGULAR EXPRESSIONS",
        std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s, self_regex))
        std::cout << "Text contains the phrase 'regular expressions'\n";
 
    std::regex word_regex("(\\w+)");
    auto words_begin = 
        std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();
 
    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";
 
    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i)
    {
        std::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N)
            std::cout << "  " << match_str << '\n';
    }
 
    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';

    std::cout << "\n\n";
    std::string location("CSV/World Inequality_all_data/WID_data_A?.csv");
    std::regex regexPtn("^(.*?)(\\[[^\\]]*\\].*|\\*.*\\$?|\\|.*|\\?.*)$", std::regex::basic);
    std::smatch s_match;
    if(std::regex_match(location, s_match, regexPtn)) {
        std::cout << "Regex Matched!\n";
        std::cout << "Prefix = " << s_match[1] << ", Pattern = " << s_match[2] << "\n";
    } else {
        std::cout << "Regex didn't match!\n";
    }
    
    std::string regexPtnStr("WID_data_A?.csv");
    regexPtn = regexPtnStr;
    std::string filename("WID_data_AD.csv");
    std::cout << "\n\n=== regex_search with pattern: " << regexPtnStr << ", filename: " << filename << " ===\n";
    if(std::regex_search(filename, regexPtn)) {
        std::cout << "Regex Matched!\n";
    } else {
        std::cout << "Regex didn't match!\n";
    }

    test_regex_search("^object", "object_match_all_files_begining_with_object.csv");
    test_regex_search("json$", "match_all_files_ending_with_json.json");
}
