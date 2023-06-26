//
//  SnapliiSDKManager.h
//  SnapliiSDK
//
//  Created by eric on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^CompletionBlock)(id responseData);
typedef void (^CallbackBlock)(CompletionBlock responseCallback);


typedef void (^GetOTPBlock)(id responseData);

@interface SnapliiSDKManager : NSObject
+(instancetype)defaultService;

//初始化SDK
-(void)initAppId:(NSString *)appId language:(NSString *)language personalToken:(NSString *)personalToken customerData:(NSString *)customerData Callback:(CallbackBlock)callback;

//是否开通了Snaplii信用付
//- (BOOL)hasSnapliiCredit;
- (void)hasSnapliiCreditCurrentController:(UIViewController *)currentController CheckCreditBlcok:(void(^)(BOOL))block;

//注册开通信用付
-(void)initSnapliiCreditCallback:(void(^)(NSString *))callback;


//配置语言
- (void)setLanguage:(NSString *)language;

//支付
- (void)payment:(NSString *)paymentSign orderAmount:(NSString *)orderAmount outterOrderNo:(NSString *)outterOrderNo CurrentController:(UIViewController *)currentController callback:(void(^)(NSString *))callback;

@property (nonatomic, copy)GetOTPBlock block;

@property (nonatomic, copy) NSString *customerData;
@end

NS_ASSUME_NONNULL_END
