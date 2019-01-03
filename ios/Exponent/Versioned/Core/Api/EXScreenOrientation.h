// Copyright 2015-present 650 Industries. All rights reserved.

#import <React/RCTBridgeModule.h>
#import <React/RCTConvert.h>

#import "EXScopedEventEmitter.h"


typedef NS_ENUM(NSInteger, EXOrientationLock) {
  DEFAULT,
  ALL,
  PORTRAIT,
  PORTRAIT_UP,
  PORTRAIT_DOWN,
  LANDSCAPE,
  LANDSCAPE_LEFT,
  LANDSCAPE_RIGHT,
  OTHER,
  ALL_BUT_UPSIDE_DOWN // deprecated
};

@interface RCTConvert (OrientationLock)

+ (EXOrientationLock)EXOrientationLock:(id)json;

@end

@protocol EXScreenOrientationScopedModuleDelegate

- (void)screenOrientationModule:(id)scopedOrientationModule
didChangeSupportedInterfaceOrientations:(UIInterfaceOrientationMask)supportedInterfaceOrientations;

- (UIInterfaceOrientationMask)supportedInterfaceOrientationsForVisibleApp;

- (void)removeOrientationChangeListener:(NSString *) experienceId;

- (void)addOrientationChangeListener:(NSString *) experienceId subscriberModule:(id) subscriberModule;

- (UITraitCollection *) getTraitCollection;

@end

@interface EXScreenOrientation : EXScopedEventEmitter <RCTBridgeModule>

- (void) handleScreenOrientationChange:(nullable UITraitCollection *) traitCollection;

+ (NSDictionary *)constantsToExport;

@end
