//
//  DemoViewController.m
//  test
//
//  Created by mPaaS on 16/11/21.
//  Copyright © 2016年 Alibaba. All rights reserved.
//

#import "DemoViewController.h"

@interface DemoViewController ()

@property (nonatomic, strong) AUButton* btn;

@end

@implementation DemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(130, 150, self.view.bounds.size.width-60, 40)];
    label.text = @"Hello World!";
    label.font = [UIFont systemFontOfSize:30];
    label.textColor = [UIColor redColor];
    [self.view addSubview:label];
    
    CGFloat margin = 0.05 * CGRectGetWidth(self.view.frame);
    self.btn.frame = CGRectMake(margin, CGRectGetMaxY(label.frame) + 150, CGRectGetWidth(self.view.frame) - 2 * margin, 44);
    [self.view addSubview:self.btn];
}

- (AUButton *)btn {
    if (!_btn) {
        _btn = [AUButton buttonWithStyle:AUButtonStyle1 title:@"打开小程序" target:self action:@selector(openTinyApp:)];
    }
    return _btn;
}

- (void)openTinyApp:(id)sender {
    NSString *appID = @"2017072607907880";
    [DTContextGet() startApplication:appID params:@{@"appId":appID,@"debug":@"framework"} animated:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
