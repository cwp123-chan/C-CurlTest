// curlTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。


#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
#include <json/json.h>
#pragma comment(lib,"json_vc71_libmtd.lib")

using namespace std;

string WriteFile(string FileName) {
    // 头文件
    // 创建流对象
    ifstream ifs;
    // 打开文件是否成功
    ifs.open(FileName,ios::in);
    if (!ifs.is_open()) {
        cout << "打开文件" + FileName + "失败" << endl;
        return "-1";
    }
    string buf;
    while (getline(ifs, buf)) {
        return buf;
    }
    ifs.close();
    return "读取失败";
}

int main(int argc, char* argv[])
{
    
        char* Str = argv[1];
        string s;
        s = Str;
        cout << typeid(s).name() << endl;
        
        if (s == "1")
        {
            cout << "开始请求..." << endl;
            char* FileNameChar = argv[2];
            string FileNameInit;
            FileNameInit = FileNameChar;
            string jsonData = WriteFile(FileNameInit);
     
            int nRoleDd = 0;
            string strOccupation = "";
            string strCamp = "";
          
            
     
            vector<int> res;
            
            while (!jsonData.empty()) {
                string Commend_curl = "curl http://127.0.0.1:6776/api/collPatients?data=";
                //如果没有空格了，则只剩下最后一个整数字符，转换为数字加入数组并清空字符串，使循环结束
                if (jsonData.find(" ") == string::npos) 
                {
                 
                    res.push_back(stoi(jsonData));
                    jsonData.clear();
                    break;
                }
                string s_temp = jsonData.substr(0, jsonData.find(" "));
             
                res.push_back(stoi(s_temp));
                jsonData.erase(0, jsonData.find(" ") + 1); //要删掉空格，所以要jsonData.find(" ") + 1    
                cout << s_temp << endl;
                Commend_curl = Commend_curl + s_temp;
                const char *CharCurlStr = Commend_curl.data();
                //cout << Commend_curl << endl;
                system(CharCurlStr);
            }

            
            //char Commend_curl[100] = "curl www.baidu.com";
            //system(Commend_curl);
            
        }  
        return 0;

}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
