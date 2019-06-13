#ifndef _OPERATION_H_
#define _OPERATION_H_

#include "headers.h"


void Input_Per_Info();                          //输入用户信息
void Verify_Per_Info();                         //用户检查输入的信息是否有误 

void Login(char *usr_name, char *usr_pwd);      //用户登录界面登录操作
bool LoginVerify(char *account, char *pwd);     //登录验证

void Register_Usr_Pwd(PerInfo *p);              //注册用户名和密码
void GenerateCardID(PerInfo *p);                //生成卡号

void del_Account(char *p);                      //删除文件中的账号信息
void fRead(PerInfo *p);                         //从文件中读取注册信息
void Record(PerInfo *p);                        //将注册信息存入文件

#endif