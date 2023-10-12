//
//  SnapliiSDKManager.h
//  SnapliiSDK
//
//  Created by eric on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^Callback)(BOOL success, NSString *code, NSString * _Nullable message);

typedef void(^GetOTPBlock)(NSString *otp);
typedef void(^OTPCallback)(GetOTPBlock getOTPBlock);

typedef Callback ApplyResultCallback;
typedef Callback HasSnapliiCreditCallback;
typedef Callback PayResultCallback;
typedef Callback LoginCallback;
typedef Callback AutoLoginCallback;

@interface SnapliiSDKManager : NSObject

+ (instancetype)defaultService;

//初始化SDK
- (void)initAppId:(NSString *)appId
         language:(NSString *)language
    personalToken:(NSString *)personalToken
       customData:(nullable NSDictionary *)customData
         callback:(OTPCallback)callback;

//是否开通了Snaplii信用付
- (void)hasSnapliiCredit:(HasSnapliiCreditCallback)completion;

//注册开通信用付
- (void)initSnapliiCredit:(UIViewController *)viewController
                    token:(nullable NSString *)campaignToken
                 callback:(ApplyResultCallback)callback;

- (void)login:(UIViewController *)viewController
     callback:(LoginCallback)callback;

//配置语言
- (void)setLanguage:(NSString *)language;

// 清除用户登陆信息
- (void)logout;

// 是否登陆
- (BOOL)hasLogin;

/*
 *  @param sandbox YES 使用sandbox环境, NO 使用生产环境
 *  不调用该接口，默认为生产环境
 *  请只在调试情况下，在 init SDK 之前调用
 */
- (void)useSandbox:(BOOL)sandbox;

//支付
- (void)payment:(NSString *)orderStr
 viewController:(UIViewController *)viewController
       callback:(PayResultCallback)callback;

- (NSString *)getVersion;

@end

NS_ASSUME_NONNULL_END
