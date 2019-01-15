//
//  MWPhotoProtocol.h
//  BeePhotoBrowser
//
//  Created by Michael Waterfall on 02/01/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

// Notifications
#define APPHOTO_LOADING_WILL_START_NOTIFICATION @"APPHOTO_LOADING_WILL_START_NOTIFICATION"
#define APPHOTO_LOADING_DID_END_NOTIFICATION    @"APPHOTO_LOADING_DID_END_NOTIFICATION"
#define APPHOTO_IMAGE_FADE_IN_NOTIFICATION      @"APPHOTO_IMAGE_FADE_IN_NOTIFICATION"
#define APPHOTO_PROGRESS_NOTIFICATION           @"APPHOTO_PROGRESS_NOTIFICATION"

typedef enum : NSUInteger {
    BEEPhotoLoadPriorityUnknow   = 0,
    BEEPhotoLoadPriorityLow      = 1,
    BEEPhotoLoadPriorityDefault  = 500,
    BEEPhotoLoadPriorityHigh     = 999,
} BEEPhotoLoadPriority;

// If you wish to use your own data models for photo then they must conform
// to this protocol. See instructions for details on each method.
// Otherwise you can use the MWPhoto object or subclass it yourself to
// store more information per photo.
//
// You can see the MWPhoto class for an example implementation of this protocol
//
@protocol BEEPhoto <NSObject>

@required

// Return underlying UIImage to be displayed
// Return nil if the image is not immediately available (loaded into memory, preferably
// already decompressed) and needs to be loaded from a source (cache, file, web, etc)
// IMPORTANT: You should *NOT* use this method to initiate
// fetching of images from any external of source. That should be handled
// in -loadUnderlyingImageAndNotify: which may be called by the photo browser if this
// methods returns nil.
@property (nonatomic, strong) UIImage *underlyingImage;

// Set this to control the priority of loading as your needs.
@property (nonatomic, assign) BEEPhotoLoadPriority priority;

// Called when the browser has determined the underlying images is not
// already loaded into memory but needs it.
- (void)loadUnderlyingImageAndNotify;

// Fetch the image data from a source and notify when complete.
// You must load the image asyncronously (and decompress it for better performance).
// It is recommended that you use SDWebImageDecoder to perform the decompression.
// See MWPhoto object for an example implementation.
// When the underlying UIImage is loaded (or failed to load) you should post the following
// notification:
// [[NSNotificationCenter defaultCenter] postNotificationName:MWPHOTO_LOADING_DID_END_NOTIFICATION
//                                                     object:self];
- (void)performLoadUnderlyingImageAndNotify;

// This is called when the photo browser has determined the photo data
// is no longer needed or there are low memory conditions
// You should release any underlying (possibly large and decompressed) image data
// as long as the image can be re-loaded (from cache, file, or URL)
- (void)unloadUnderlyingImage;

@optional

// Return a caption string to be displayed over the image
// Return nil to display no caption
- (NSString *)caption;

// Cancel any background loading of image data
- (void)cancelAnyLoading;

@end

__deprecated_msg("直接使用BEEPhoto")
@protocol APPhoto <BEEPhoto>

@end
