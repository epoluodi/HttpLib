//
//  ReturnData.h
//  stereo
//
//  Created by 程嘉雯 on 15/9/7.
//  Copyright (c) 2015年 com.suypower.stereo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ReturnData : NSObject

//消息代码
@property (assign,nonatomic) NSInteger *returnCode;
//消息体json
@property (copy,nonatomic) NSDictionary *returnData;
//消息体json数组
@property (copy,nonatomic) NSArray *returnDatas;
//消息信息
@property (copy,nonatomic)NSString *returnMsg;
@property (strong,nonatomic)NSString *errMsg;


//消息解析
+(instancetype)getReturnData:(NSString *)json dataMode:(BOOL)dataMode;
+(instancetype)getReturnDatawithData:(NSData *)jsondata dataMode:(BOOL)dataMode;
@end
