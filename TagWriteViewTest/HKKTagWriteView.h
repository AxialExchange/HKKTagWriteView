//
//  HKKTagWriteView.h
//  TagWriteViewTest
//
//  Created by kyokook on 2014. 1. 11..
//  Copyright (c) 2014 rhlab. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol HKKTagWriteViewDelegate;

@interface HKKTagWriteView : UIView

//
// appearance
//
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *tagBackgroundColor;
@property (nonatomic, strong) UIColor *tagForegroundColor;
@property (nonatomic, assign) int maxTagLength;
@property (nonatomic, assign) CGFloat tagGap;
@property (nonatomic, assign) CGFloat tagCornerRadius;

//
// data
//
@property (nonatomic, readonly) NSArray<NSString *> *tags;

//
// control
//
@property (nonatomic, assign) BOOL focusOnAddTag;
@property (nonatomic, assign) BOOL allowToUseSingleSpace;

@property (nonatomic, weak) id<HKKTagWriteViewDelegate> delegate;

- (void)clear;
- (void)setTextToInputSlot:(NSString *)text;
- (void)layoutInputAndScroll; // call after setting cornerRadius

- (void)addTags:(NSArray *)tags;
- (void)removeTags:(NSArray *)tags;
- (void)addTagToLast:(NSString *)tag animated:(BOOL)animated;
- (void)removeTag:(NSString *)tag animated:(BOOL)animated;

@property (readonly) BOOL becomeFirstResponder;

@end

@protocol HKKTagWriteViewDelegate <NSObject>
@optional
- (void)tagWriteViewDidBeginEditing:(HKKTagWriteView *)view;
- (void)tagWriteViewDidEndEditing:(HKKTagWriteView *)view;

- (void)tagWriteView:(HKKTagWriteView *)view didChangeText:(NSString *)text;
- (void)tagWriteView:(HKKTagWriteView *)view didMakeTag:(NSString *)tag;
- (void)tagWriteView:(HKKTagWriteView *)view didRemoveTag:(NSString *)tag;
@end


