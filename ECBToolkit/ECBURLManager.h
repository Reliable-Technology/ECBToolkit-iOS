//
//  ECBURLManager.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/5/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECBURLManager : NSObject

@property (nonatomic, strong) NSString *redirectionURL;

+ (instancetype)sharedManager;
- (NSString *)webServiceURL;
- (NSString *)webServiceURLForEndPoint:(NSString *)endPoint;

@end
