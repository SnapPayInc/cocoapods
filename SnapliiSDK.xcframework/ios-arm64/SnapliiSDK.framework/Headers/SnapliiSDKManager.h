//
//  SnapliiSDKManager.h
//  SnapliiSDK
//
//  Created by eric on 2023/5/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^Callback)(BOOL success, NSString * _Nullable message);

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
     customerData:(NSString *)customerData
         callback:(OTPCallback)callback;

//是否开通了Snaplii信用付
- (void)hasSnapliiCredit:(HasSnapliiCreditCallback)completion;

//注册开通信用付
- (void)initSnapliiCredit:(ApplyResultCallback)callback;


//配置语言
- (void)setLanguage:(NSString *)language;

- (void)login:(UIViewController *)currentController
     callback:(LoginCallback)callback;

// 清除用户登陆信息
- (void)logout;

// 是否登陆
- (BOOL)hasLogin;

//支付
- (void)payment:(NSString *)paymentSign
    orderAmount:(NSString *)orderAmount
  outterOrderNo:(NSString *)outterOrderNo
 viewController:(UIViewController *)viewController
       callback:(PayResultCallback)callback;

@end

NS_ASSUME_NONNULL_END
