#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <sstream>
#include <vector>

// 声明全局变量，十个基本称呼及基本关系代号
const std::vector<std::string> call_list = { "女儿", "儿子", "丈夫", "妻子", "哥哥", "弟弟", "姐姐", "妹妹", "爸爸", "妈妈" };
const std::vector<char> code_list = { 'N', 'Z', 'F', 'Q', 'G', 'D', 'J', 'S', 'B', 'M' };

bool input_check(const std::string& str_in) {
    /**
     * 使用正则表达式检查输入是否合法
     * :param str_in: 中文字符串输入
     * :return bool: 返回是否满足输入要求的逻辑值
     */
    std::regex correct_enter(R"(^([女儿|儿子|丈夫|妻子|老公|老婆|哥哥|弟弟|姐姐|妹妹|爸爸|妈妈][的]?)+$)");
    return std::regex_match(str_in, correct_enter);
}

std::string input_handle(const std::string& str_in) {
    /**
     * 中文输入的基本分词
     * :param str_in: 符合输入要求的中文字符串
     * :return seq: 返回中文字符串对应的完整代号序列字符串
     */
     // 创建中文转换识别字典
    std::map<std::string, char> call_dic;
    for (size_t i = 0; i < call_list.size(); ++i) {
        call_dic[call_list[i]] = code_list[i];
    }
    // 补充几个常用的称呼提升输入多样性
    call_dic["老公"] = 'F';
    call_dic["老婆"] = 'Q';

    std::istringstream strStream(str_in);
    std::string token;
    std::string sequence;

    while (getline(strStream, token, '的')) {
        sequence += call_dic[token];
    }

    return sequence;
}

int gender_check(const std::string& seq_in) {
    /**
     * 性别判定
     * :param seq_in: 代号序列
     * :return: 返回最后一个代号的性别，1为男，0为女
     */
    std::map<char, int> gender_dic = { {'N', 0}, {'Z', 1}, {'F', 1}, {'Q', 0},
                                      {'G', 1}, {'D', 1}, {'J', 0}, {'S', 0},
                                      {'B', 1}, {'M', 0} };

    char last_char = seq_in.back(); // 获取字符串的最后一个字符
    return gender_dic[last_char]; // 返回该字符对应的性别
}

std::string seq_simplify(const std::string& input) {
    std::string seq_in = input;
    // 可直接替换的32组可折叠代号组合
    std::vector<std::string> folded_call = {
        "NG", "ND", "NJ", "NS", "ZG", "ZD", "ZJ", "ZS", "FN", "FZ",
        "QN", "QZ", "GG", "GJ", "GB", "GM", "DD", "DS", "DB", "DM",
        "JG", "JJ", "JB", "JM", "SD", "SS", "SB", "SM", "BQ", "MF",
        "FQ", "QF"
    };
    std::vector<std::string> replaced_call_1 = {
        "Z", "Z", "N", "N", "Z", "Z", "N", "N", "N", "Z",
        "N", "Z", "G", "J", "B", "M", "D", "S", "B", "M",
        "G", "J", "B", "M", "D", "S", "B", "M", "M", "B",
        "", ""
    };
    // 需判断前点性别的16组可折叠代号组合
    std::vector<std::string> wrong_call = {
        "GD", "GS", "DG", "DJ", "JD", "JS", "SG", "SJ",
        "NB", "NM", "ZB", "ZM", "BN", "BZ", "MN", "MZ"
    };
    std::vector<std::string> replace_call_2 = {
        "D", "S", "G", "J", "D", "S", "G", "J",
        "F", "Q", "F", "Q", "S", "D", "M", "D"
    };

    // 构建替换字典
    std::map<std::string, std::string> replace_dic;
    for (size_t i = 0; i < folded_call.size(); ++i) {
        replace_dic[folded_call[i]] = replaced_call_1[i];
    }
    for (size_t i = 0; i < wrong_call.size(); ++i) {
        replace_dic[wrong_call[i]] = replace_call_2[i];
    }

    bool changed;
    do {
        changed = false;
        for (const auto& [key, value] : replace_dic) {
            size_t pos = seq_in.find(key);
            if (pos != std::string::npos) {
                if (key.length() == 2 && pos > 0 && seq_in.length() > pos + 1 &&
                    gender_check(seq_in.substr(pos - 1, 1)) != gender_check(seq_in.substr(pos + 2, 1))) {
                    seq_in.replace(pos, key.length(), value);
                    changed = true;
                }
                else if (key.length() == 2 && pos > 0 && seq_in.length() > pos + 1 &&
                    gender_check(seq_in.substr(pos - 1, 1)) == gender_check(seq_in.substr(pos + 2, 1))) {
                    seq_in.erase(pos, key.length());
                    changed = true;
                }
                else {
                    seq_in.replace(pos, key.length(), value);
                    changed = true;
                }
            }
        }
    } while (changed);

    return seq_in;
}

bool seq_check(const std::string& seq_in) {
    /**
     * 代号序列压缩完毕，再检查是否有错误代号或超长
     * :param seq_in: 序列字符串
     * :return: 返回逻辑值，true表示序列有效，false表示无效
     */
    std::vector<std::string> error_call = { "NQ", "ZF", "FF", "QQ", "GF", "DF", "JQ", "SQ", "BF", "MQ" };
    bool result = true;

    for (const auto& i : error_call) {
        if (seq_in.find(i) != std::string::npos) {
            std::cout << "输入有误，还不明确该如何处理同性婚姻……" << std::endl;
            result = false;
            break;
        }
    }

    if (seq_in.length() > 6) {
        std::cout << "这个人好像跟你没什么关系啊" << std::endl; // 压缩后还超过6个节点说明实在太远
        result = false;
    }

    return result;
}

// Define the relationship map for nested relationships
using Relationship = std::map<std::string, std::string>;
using SecondLevelRelationship = std::map<std::string, Relationship>;
using TopLevelRelationship = std::map<std::string, SecondLevelRelationship>;

// Initialization function for the relationship structure
TopLevelRelationship initRelationships() {
    TopLevelRelationship The_dict;

    // Initialize third-level relationships
    Relationship sunzi = { {"N", "曾孙女"}, {"Z", "曾孙"}, {"Q", "孙媳妇"}, {"I", "孙子"} };
    Relationship sunnv = { {"N", "曾外孙女"}, {"Z", "曾外孙"}, {"F", "孙女婿"}, {"I", "孙女"} };
    Relationship waisun = { {"N", "外曾孙女"}, {"Z", "外曾孙"}, {"Q", "外孙媳"}, {"I", "外孙"} };
    Relationship waisunnv = { {"N", "外增外孙女"}, {"Z", "外曾外孙"}, {"F", "外孙女婿"}, {"I", "外孙女"} };
    Relationship zhizi = { {"N", "侄孙女"}, {"Z", "侄孙"}, {"Q", "侄媳妇"}, {"I", "侄子"} };
    Relationship zhinv = { {"N", "外侄孙女"}, {"Z", "外侄孙"}, {"F", "侄女婿"}, {"I", "侄女"} };
    Relationship waisheng = { {"N", "外甥孙女"}, {"Z", "外甥孙"}, {"Q", "外甥媳妇"}, {"I", "外甥"} };
    Relationship waishengnv = { {"N", "外甥孙女"}, {"Z", "外甥孙"}, {"F", "外甥女婿"}, {"I", "外甥女"} };
    Relationship erxi = { {"G", "姻侄"}, {"D", "姻侄"}, {"J", "姻侄女"}, {"S", "姻侄女"}, {"B", "亲家公"}, {"M", "亲家母"}, {"I", "儿媳"} };
    Relationship nvxu = { {"G", "姻侄"}, {"D", "姻侄"}, {"J", "姻侄女"}, {"S", "姻侄女"}, {"B", "亲家公"}, {"M", "亲家母"}, {"I", "女婿"} };
    Relationship dimei = { {"G", "姻兄弟"}, {"D", "姻兄弟"}, {"J", "姻姐妹"}, {"S", "姻姐妹"}, {"B", "姻伯父（叫叔叔就行）"}, {"M", "姻伯母（叫阿姨就行）"}, {"I", "弟妹"} };
    Relationship saozi = { {"G", "姻兄弟"}, {"D", "姻兄弟"}, {"J", "姻姐妹"}, {"S", "姻姐妹"}, {"B", "姻伯父（叫叔叔就行）"}, {"M", "姻伯母（叫阿姨就行）"}, {"I", "嫂子"} };
    Relationship jiefu = { {"G", "姻兄弟"}, {"D", "姻兄弟"}, {"J", "姻姐妹"}, {"S", "姻姐妹"}, {"B", "姻伯父（叫叔叔就行）"}, {"M", "姻伯母（叫阿姨就行）"}, {"I", "姐夫"} };
    Relationship meifu = { {"G", "姻兄弟"}, {"D", "姻兄弟"}, {"J", "姻姐妹"}, {"S", "姻姐妹"}, {"B", "姻伯父（叫叔叔就行）"}, {"M", "姻伯母（叫阿姨就行）"}, {"I", "妹夫"} };

    Relationship xiaojiuzi = { {"N", "内侄女"}, {"Z", "内侄"}, {"Q", "舅弟媳"}, {"I", "小舅子"} };
    Relationship dajiuzi = { {"N", "内侄女"}, {"Z", "内侄"}, {"Q", "舅嫂"}, {"I", "大舅子"} };
    Relationship dayizi = { {"N", "姨甥女"}, {"Z", "内甥"}, {"F", "大姨夫，跟着叫姐夫吧"}, {"I", "大姨子"} };
    Relationship xiaoyizi = { {"N", "姨甥女"}, {"Z", "内甥"}, {"F", "小姨夫，跟着叫妹夫吧"}, {"I", "小姨子"} };
    Relationship xiaoshuzi = { {"N", "侄女"}, {"Z", "叔侄"}, {"Q", "小婶子"}, {"I", "小叔子"} };
    Relationship dabozi = { {"N", "侄女"}, {"Z", "叔侄"}, {"Q", "大婶子"}, {"I", "大伯子"} };
    Relationship daguzi = { {"N", "姑甥女"}, {"Z", "姑甥"}, {"F", "大姑父，跟着叫姐夫吧"}, {"I", "大姑子"} };
    Relationship xiaoguzi = { {"N", "姑甥女"}, {"Z", "姑甥"}, {"F", "小姑父，跟着叫妹夫吧"}, {"I", "小姑子"} };
    Relationship shufu = { {"N", "堂姐妹"}, {"Z", "堂兄弟"}, {"Q", "婶婶"}, {"I", "叔父"} };
    Relationship bofu = { {"N", "堂姐妹"}, {"Z", "堂兄弟"}, {"Q", "婶婶"}, {"I", "伯父"} };
    Relationship gugu = { {"N", "姑表姐妹"}, {"Z", "姑表兄弟"}, {"F", "姑父"}, {"I", "姑姑"} };
    Relationship jiujiu = { {"N", "舅表姐妹"}, {"Z", "舅表兄弟"}, {"Q", "舅妈"}, {"I", "舅舅"} };
    Relationship yima = { {"N", "姨表姐妹"}, {"Z", "姨表兄弟"}, {"F", "姨父"}, {"I", "姨妈"} };

    // Define each relationship in the family tree
    Relationship yuefu = { {"G", "伯岳父（媳妇咋叫你咋叫）"}, {"D", "叔岳父（媳妇咋叫你咋叫）"}, {"J", "姑岳母（媳妇咋叫你咋叫）"}, {"S", "姑岳母（媳妇咋叫你咋叫）"}, {"B", "太岳父（媳妇咋叫你咋叫）"}, {"M", "太岳母（媳妇咋叫你咋叫）"}, {"I", "岳父"} };
    Relationship yuemu = { {"G", "舅岳父（媳妇咋叫你咋叫）"}, {"D", "舅岳父（媳妇咋叫你咋叫）"}, {"J", "姨岳母（媳妇咋叫你咋叫）"}, {"S", "姨岳母（媳妇咋叫你咋叫）"}, {"B", "外太岳父（媳妇咋叫你咋叫）"}, {"M", "外太岳母（媳妇咋叫你咋叫）"}, {"I", "岳母"} };
    Relationship gongong = { {"G", "伯翁（老公咋叫你咋叫）"}, {"D", "叔公（老公咋叫你咋叫）"}, {"J", "姑婆（老公咋叫你咋叫）"}, {"S", "姑婆（老公咋叫你咋叫）"}, {"B", "祖翁（老公咋叫你咋叫）"}, {"M", "祖婆（老公咋叫你咋叫）"}, {"I", "公公"} };
    Relationship popo = { {"G", "舅公（老公咋叫你咋叫）"}, {"D", "舅公（老公咋叫你咋叫）"}, {"J", "姨婆（老公咋叫你咋叫）"}, {"S", "姨婆（老公咋叫你咋叫）"}, {"B", "外公"}, {"M", "外婆"}, {"I", "婆婆"} };
    Relationship yeye = { {"G", "伯祖父"}, {"D", "叔祖父"}, {"J", "姑奶奶"}, {"S", "姑奶奶"}, {"B", "曾祖父"}, {"M", "曾祖母"}, {"I", "爷爷"} };
    Relationship nainai = { {"G", "舅公"}, {"D", "舅公"}, {"J", "姨奶奶"}, {"S", "姨奶奶"}, {"B", "曾外祖父"}, {"M", "曾外祖母"}, {"I", "奶奶"} };
    Relationship laoye = { {"G", "伯外祖父"}, {"D", "伯外祖父"}, {"J", "姑姥姥"}, {"S", "姑姥姥"}, {"B", "外曾祖父"}, {"M", "外曾祖母"}, {"I", "姥爷"} };
    Relationship laolao = { {"G", "外舅公"}, {"D", "外舅公"}, {"J", "姨姥姥"}, {"S", "姨姥姥"}, {"B", "外曾外祖父"}, {"M", "外曾外祖母"}, {"I", "姥姥"} };

    // Initialize second-level relationships
    SecondLevelRelationship nver = { {"N", waisunnv}, {"Z", waisun}, {"F", nvxu}, {"I", "女儿"} };
    SecondLevelRelationship erzi = { {"N", sunnv}, {"Z", sunzi}, {"Q", erxi}, {"I", "儿子"} };
    SecondLevelRelationship zhangfu = { {"G", jiefu}, {"D", dimei}, {"J", saozi}, {"S", meifu}, {"B", "公公"}, {"M", "婆婆"}, {"I", "丈夫"} };
    SecondLevelRelationship qizi = { {"G", jiefu}, {"D", dimei}, {"J", saozi}, {"S", meifu}, {"B", "岳父"}, {"M", "岳母"}, {"I", "妻子"} };
    SecondLevelRelationship gege = { {"N", zhinv}, {"Z", zhizi}, {"Q", saozi}, {"I", "哥哥"} };
    SecondLevelRelationship didi = { {"N", zhinv}, {"Z", zhizi}, {"Q", dimei}, {"I", "弟弟"} };
    SecondLevelRelationship jiejie = { {"N", waishengnv}, {"Z", waisheng}, {"F", jiefu}, {"I", "姐姐"} };
    SecondLevelRelationship meimei = { {"N", waishengnv}, {"Z", waisheng}, {"F", meifu}, {"I", "妹妹"} };
    SecondLevelRelationship baba = { {"G", gege}, {"D", didi}, {"J", jiejie}, {"S", meimei}, {"B", "祖父"}, {"M", "祖母"}, {"I", "爸爸"} };
    SecondLevelRelationship mama = { {"G", gege}, {"D", didi}, {"J", jiejie}, {"S", meimei}, {"B", "外祖父"}, {"M", "外祖母"}, {"I", "妈妈"} };

    // Initialize top-level relationship
    The_dict = { {"N", nver}, {"Z", erzi}, {"F", zhangfu}, {"Q", qizi}, {"G", gege}, {"D", didi}, {"J", jiejie}, {"S", meimei}, {"B", baba}, {"M", mama} };

    return The_dict;
}

std::string main_cal(const std::string& s) {
    TopLevelRelationship The_dict = initRelationships();
    std::string result = "这位是你的";

    if (s.length() == 1) {
        result += The_dict[s.substr(0, 1)]["I"]["I"];
    }
    else if (s.length() == 2) {
        result += The_dict[s.substr(0, 1)][s.substr(1, 1)]["I"];
    }
    else if (s.length() == 3) {
        result += The_dict[s.substr(0, 1)][s.substr(1, 1)][s.substr(2, 1)];
    }
    else {
        // Handle sequences longer than three characters
        result += The_dict[s.substr(0, 1)][s.substr(1, 1)][s.substr(2, 1)];
        result += "的";
        result += main_cal(s.substr(3)); // Recursively process the rest
    }

    return result;
}

void menu() {
    // 打印菜单以指导如何使用亲戚计算器
    std::cout << std::string(70, '#') << std::endl << std::endl;
    std::cout << "     欢迎使用极其简易版亲戚计算器 Kinship_Calculation 0.1      " << std::endl << std::endl;
    std::cout << std::string(70, '#') << std::endl << std::endl;
    std::cout << "目前功能还很低级，只能计算以下十种关系的组合：" << std::endl;
    std::cout << "女儿、儿子、丈夫、妻子、哥哥、弟弟、姐姐、妹妹、爸爸、妈妈" << std::endl;
    std::cout << "请用‘的’连接你想计算的亲戚关系，如爸爸的妈妈的姐姐，按Enter查看结果，按Q退出：" << std::endl;
}

void example() {
    // Define a list of example relationships to demonstrate the calculator
    std::vector<std::string> examples = {
        "爸爸的妈妈的姐姐的老公的弟弟的老婆",
        "老婆的哥哥的妹妹的姐姐的爸爸的老婆的爸爸的姐姐的老公",
        "哥哥的儿子的姐姐的老公的爸爸的妹妹的老公",
        "哥哥的弟弟的姐姐的妹妹的爸爸的妈妈的姐姐的妈妈的女儿的老公的姐姐"
    };

    for (const auto& i : examples) {
        std::string sequence = input_handle(i);
        sequence = seq_simplify(sequence);
        if (seq_check(sequence)) {
            std::cout << i << std::endl;
            std::cout << main_cal(sequence) << std::endl;
        }
    }
    std::cout << "………………\nExample finished, please enter the relationship you want to calculate:" << std::endl;
}

int main() {
    // Display the initial menu
    menu();

    std::string the_str;

    while (true) {
        // Get input from user
        std::getline(std::cin, the_str);

        // Convert input to upper case to check for 'Q' command to quit
        if (the_str == "Q" || the_str == "q") {
            std::cout << "退出计算器" << std::endl;
            break;
        }
        else if (the_str == "show") {
            // Display examples
            example();
        }
        else if (input_check(the_str)) {
            // Process the kinship calculation
            std::string seq = input_handle(the_str);
            seq = seq_simplify(seq);
            if (seq_check(seq)) {
                std::cout << main_cal(seq) << std::endl;
            }
        }
        else {
            // Handle incorrect input
            std::cout << "输入有问题呐，人家又没有搞自然语言处理，很笨的只会按照示例计算，请重新输入：" << std::endl;
        }
    }

    // Pause the system to prevent the console window from closing immediately
    std::system("pause");  // This is platform-dependent (Windows)
    return 0;
}

