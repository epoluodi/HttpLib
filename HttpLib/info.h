//
//  info.h
//  HttpClass
//
//  Created by 程嘉雯 on 15/5/28.
//  Copyright (c) 2015年 com.epoluodi.lib. All rights reserved.
//





struct AppleDeviceInfo
{
    const char *Apple_Token;
    const char *apple_Model;
    const char *apple_system_ver;
    const char *apple_syatem_name;
    const char *apple_uuid;
    const char *apple_Code;
};

typedef struct AppleDeviceInfo AppleDeviceInfoStruct;

@protocol Httpdelegate
//异步执行返回
-(void)reposenHttp:(NSData *)data;
-(void)httpFail;
-(void)httpDownloadprocess:(float)persent;

@end
