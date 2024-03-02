//
//  SnapliiSDKManager.h
//  SnapliiSDK
//
//  Created by eric on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SnapliiCreditInfo;

typedef void(^GetOTPBlock)(NSString *otp);
typedef void(^OTPCallback)(GetOTPBlock getOTPBlock);

// 无参数回调 成功/取消 VoidCallback
typedef void (^VoidCallback)(void);

// 失败回调 Callback
typedef void (^Callback)(NSString *code, NSString *message);

// 结果回调，包含成功和失败信息
typedef void (^ResultCallback)(BOOL success, NSString * _Nullable code,  NSString * _Nullable message);

typedef void (^ApplyCompletionCallback)(NSString * _Nullable extraInfo);
typedef VoidCallback ApplyCancelCallback;

typedef VoidCallback PaySuccessCallback;
typedef VoidCallback PayCancelCallback;
typedef Callback PayFailureCallback;

typedef VoidCallback LoginSuccessCallback;
typedef VoidCallback LoginCancelCallback;

typedef void (^HasSnapliiCreditCallback)(BOOL success, NSString * _Nullable code, NSString * _Nullable message);

typedef void (^CreditInfoCallback)(SnapliiCreditInfo * _Nullable creditInfo, NSString * _Nullable message);

typedef NSString *SnapliiApplyStatus NS_STRING_ENUM;

// 已通过 "APPROVED"
FOUNDATION_EXPORT SnapliiApplyStatus const SnapliiApplyStatusApproved;
// 可申请 "APPLICABLE"
FOUNDATION_EXPORT SnapliiApplyStatus const SnapliiApplyStatusApplicable;
// 申请处理中 "IN_PROGRESS"
FOUNDATION_EXPORT SnapliiApplyStatus const SnapliiApplyStatusInProgress;
// 不可申请 "NOT_APPLICABLE"
FOUNDATION_EXPORT SnapliiApplyStatus const SnapliiApplyStatusNotApplicable;

@interface SnapliiCreditInfo : NSObject

@property (nonatomic, copy, readonly) NSString *totalCredit;
@property (nonatomic, copy, readonly) NSString *availableCredit;
@property (nonatomic, copy, readonly) SnapliiApplyStatus applyStatus;

@end

@interface SnapliiSDKManager : NSObject

+ (instancetype)defaultService;

//初始化SDK
- (void)initAppId:(NSString *)appId
         language:(NSString *)language
    personalToken:(NSString *)personalToken
 customDataString:(nullable NSString *)customDataString
     initCallback:(ResultCallback)initCallback;

- (void)initAppId:(NSString *)appId
         language:(NSString *)language
    personalToken:(NSString *)personalToken
 customDataString:(nullable NSString *)customDataString
         callback:(nullable OTPCallback)callback;

- (void)setOTPCallback:(OTPCallback)callback;

//配置语言
- (void)setLanguage:(NSString *)language;

//是否开通了Snaplii信用付
- (void)hasSnapliiCredit:(HasSnapliiCreditCallback)completion;

//查询 Snaplii Credit 信息
- (void)queryCreditInfo:(nullable NSString *)mobile
                  email:(nullable NSString *)email
     creditInfoCallback:(CreditInfoCallback)creditInfoCallback;

//注册开通信用付
- (void)applySnapliiCredit:(UIViewController *)viewController
                     token:(nullable NSString *)campaignToken
                    mobile:(NSString *)mobile
                     email:(NSString *)email
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

//支付
- (void)payment:(NSString *)orderStr
    showLoading:(BOOL)showLoading
 viewController:(UIViewController *)viewController
        success:(PaySuccessCallback)success
        failure:(PayFailureCallback)failure
         cancel:(PayCancelCallback)cancel;

// 打开信用付信息首页
- (void)enterCreditHomePage:(UIViewController *)viewController;

- (NSString *)getVersion;

@end

NS_ASSUME_NONNULL_END
