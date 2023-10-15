//
//  SNViewController.h
//  SnapliiSDK
//
//  Created by eric on 2023/4/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNViewController : UIViewController

@property (nonatomic, assign) BOOL lightStyle;

/** 用于记录当前页面的导航栏是否需要隐藏，从其他页面返回时使用 */
@property (nonatomic, assign) BOOL isHiddenNavigationBarWhenWillAppear;

- (void)viewWillFirstAppear:(BOOL)animated;
- (void)viewDidFirstAppear:(BOOL)animated;

@property (nonatomic, assign) BOOL keyboardManagerEnabled;
@property (nonatomic, assign) CGFloat keyboardDistanceFromTextField;

@end

NS_ASSUME_NONNULL_END
