//
//  SnapliiSDKManager.h
//  SnapliiSDK
//
//  Created by eric on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^GetOTPBlock)(NSString *otp);
typedef void(^OTPCallback)(GetOTPBlock getOTPBlock);

// 无参数回调 成功/取消 VoidCallback
typedef void (^VoidCallback)(void);

// 失败回调 Callback
typedef void (^Callback)(NSString *code, NSString *message);

typedef VoidCallback ApplyCompletionCallback;
typedef VoidCallback ApplyCancelCallback;

typedef VoidCallback PaySuccessCallback;
typedef VoidCallback PayCancelCallback;
typedef Callback PayFailureCallback;

typedef VoidCallback LoginSuccessCallback;
typedef VoidCallback LoginCancelCallback;

typedef void (^HasSnapliiCreditCallback)(BOOL success, NSString * _Nullable code, NSString * _Nullable message);

@interface SnapliiSDKManager : NSObject

+ (instancetype)defaultService;

//初始化SDK
- (void)initAppId:(NSString *)appId
         language:(NSString *)language
    personalToken:(NSString *)personalToken
       customData:(nullable NSDictionary *)customData
         callback:(OTPCallback)callback;

- (void)initAppId:(NSString *)appId
         language:(NSString *)language
    personalToken:(NSString *)personalToken
 customDataString:(nullable NSString *)customDataString
         callback:(OTPCallback)callback;

//配置语言
- (void)setLanguage:(NSString *)language;

//是否开通了Snaplii信用付
- (void)hasSnapliiCredit:(HasSnapliiCreditCallback)completion;

//注册开通信用付
- (void)applySnapliiCredit:(UIViewController *)viewController
                     token:(nullable NSString *)campaignToken
                completion:(ApplyCompletionCallback)completion
                    cancel:(ApplyCancelCallback)cancel;

- (void)applySnapliiCredit:(NSString *)landingUrl
            viewController:(UIViewController *)viewController
                     token:(nullable NSString *)campaignToken
                completion:(ApplyCompletionCallback)completion
                    cancel:(ApplyCancelCallback)cancel;

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
        success:(PaySuccessCallback)success
        failure:(PayFailureCallback)failure
         cancel:(PayCancelCallback)cancel;

- (NSString *)getVersion;

@end

NS_ASSUME_NONNULL_END
