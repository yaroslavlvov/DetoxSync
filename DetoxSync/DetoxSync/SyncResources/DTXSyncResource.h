//
//  DTXSyncResource.h
//  DetoxSync
//
//  Created by Leo Natan (Wix) on 7/28/19.
//  Copyright © 2019 wix. All rights reserved.
//

#import <Foundation/Foundation.h>

#define _DTXStringReturningBlock(...) ^ { return __VA_ARGS__; }
#define _DTXObjectReturningBlock(...) ^ { return __VA_ARGS__; }

NS_ASSUME_NONNULL_BEGIN

NSString* _DTXPluralIfNeeded(NSString* word, NSUInteger count);

@interface DTXSyncResource : NSObject

@property (nonatomic, copy) NSString* name;

- (void)performUpdateBlock:(NSUInteger(NS_NOESCAPE ^)(void))block
		   eventIdentifier:(NSString*(NS_NOESCAPE ^)(void))eventID
		  eventDescription:(nullable NSString*(NS_NOESCAPE ^)(void))eventDescription
		 objectDescription:(nullable NSString*(NS_NOESCAPE ^)(void))objectDescription
	 additionalDescription:(nullable NSString*(NS_NOESCAPE ^)(void))additionalDescription;

- (void)performMultipleUpdateBlock:(NSUInteger(NS_NOESCAPE ^)(void))block
				  eventIdentifiers:(NSArray<NSString*(^)(void)>*(NS_NOESCAPE ^)(void))eventIDs
				 eventDescriptions:(nullable NSArray<NSString*(^)(void)>*(NS_NOESCAPE ^)(void))eventDescriptions
				objectDescriptions:(nullable NSArray<NSString*(^)(void)>*(NS_NOESCAPE ^)(void))objectDescriptions
			additionalDescriptions:(nullable NSArray<NSString*(^)(void)>*(NS_NOESCAPE ^)(void))additionalDescriptions;

- (NSString*)syncResourceGenericDescription;
- (NSString*)syncResourceDescription;

- (NSString*)history;

@end

NS_ASSUME_NONNULL_END
