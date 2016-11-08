//
//  HttpClass.h
//  HttpClass
//
//  Created by 程嘉雯 on 15/5/27.
//  Copyright (c) 2015年 com.epoluodi.lib. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "info.h"


@interface HttpClass : NSObject <NSURLConnectionDelegate,NSXMLParserDelegate,NSURLConnectionDataDelegate>
{
    NSMutableArray *mutableArrary;
    NSMutableData *recivedata;
    NSObject <Httpdelegate> *_delegate;
    NSMutableString *xmlstring;
    NSMutableDictionary *mutableDictionary;
   
}

@property (strong,nonatomic)NSString *WebServiceUrl;
@property (assign)BOOL isHead;

-(instancetype)init;
-(instancetype)init:(NSString *)url;



-(void)clearArray;//清空参数和头信息

//添加头
-(void)addHeadString:(NSString *)Key value:(NSString *)values;
//添加参数
-(void)addParamsString:(NSString *)key values:(NSString *)values;

//获得参数data
-(NSData*)dataEncodeDictionary:(NSDictionary*)dictionary;

//获得参数data
-(NSData *)getDataForArrary;
-(NSData*)UploadFile:(NSString *)filename FileData:(NSData *)data contenttype:(NSString *)contenttype; 

-(NSData *)httprequest:(NSData *)body;
-(BOOL)httprequest:(NSData *)body
                delegate:(NSObject<Httpdelegate> *)delegate;
-(NSString *)getXmlString:(NSData *)data;
-(NSString *)httprequestForGet:(NSString *)url;





@end


