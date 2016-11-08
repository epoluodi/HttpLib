//
//  ReturnData.m
//  stereo
//
//  Created by 程嘉雯 on 15/9/7.
//  Copyright (c) 2015年 com.suypower.stereo. All rights reserved.
//

#import "ReturnData.h"

@implementation ReturnData
@synthesize returnCode;
@synthesize returnData;
@synthesize returnDatas;
@synthesize returnMsg;
@synthesize errMsg;


+(instancetype)getReturnData:(NSString *)json dataMode:(BOOL)dataMode
{
    NSLog(@"解析 --json:%@",json);
    ReturnData *rd = [ReturnData new];
    NSError *err = nil;

    if (json == nil){
        rd.returnCode = 9999;
        return rd;
    }
    NSDictionary *main = [NSJSONSerialization JSONObjectWithData:[json dataUsingEncoding:NSUTF8StringEncoding] options:NSJSONReadingMutableContainers error:&err];
    if(err || main == nil)
    {
        rd.returnCode = 9999;
        rd.errMsg =[err localizedDescription];
        return rd;
    }
    
    rd.returnCode = ((NSString *)[main objectForKey:@"status"]).integerValue;
    if (dataMode)
        rd.returnData = [main objectForKey:@"data"];
    else
        rd.returnDatas = [main objectForKey:@"data"];
    rd.returnMsg = [main objectForKey:@"msg"];
    
    return rd;
}

+(instancetype)getReturnDatawithData:(NSData *)jsondata dataMode:(BOOL)dataMode
{
  
    ReturnData *rd = [ReturnData new];
    NSError *err = nil;
    
    if (jsondata == nil){
        rd.returnCode = 9999;
        return rd;
    }
    NSDictionary *main = [NSJSONSerialization JSONObjectWithData:jsondata options:NSJSONReadingMutableContainers error:&err];
    if(err || main == nil)
    {
        rd.returnCode = 9999;
        rd.errMsg =[err localizedDescription];
        return rd;
    }
    NSLog(@"status %@",(NSString *)[main objectForKey:@"status"]);
    rd.returnCode = ((NSString *)[main objectForKey:@"status"]).integerValue;
    if (dataMode)
        rd.returnData = [main objectForKey:@"data"];
    else
        rd.returnDatas = [main objectForKey:@"data"];
    rd.returnMsg = [main objectForKey:@"msg"];
    
    return rd;
}
@end
