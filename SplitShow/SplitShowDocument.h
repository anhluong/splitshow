//
//  SplitShowDocument.h
//  SplitShow
//
//  Created by Moritz Pflanzer on 30/09/2015.
//  Copyright © 2015 Moritz Pflanzer. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class PDFDocument;

#define kSplitShowSlideModeNormal @"kSplitShowSlideModeNormal"
#define kSplitShowSlideModeSplit @"kSplitShowSlideModeSplit"

#define kSplitShowSlideGroupContent @"kSplitShowSlideGroupContent"
#define kSplitShowSlideGroupNotes @"kSplitShowSlideGroupNotes"

enum SplitShowError
{
    SplitShowPresentationLoadError,
};

@interface SplitShowDocument : NSDocument

@property NSArray *layouts;

@property (readonly) NSString *name;
@property (readonly) BOOL hasInterleavedLayout;
@property (readonly) NSSize pageSize;

- (PDFDocument*)createInterleavedDocumentForGroup:(NSString*)group;
- (PDFDocument*)createSplitDocumentForGroup:(NSString*)group;
- (PDFDocument*)createMirroredDocument;
- (PDFDocument*)createDocumentFromIndices:(NSArray*)indices inMode:(NSString*)mode;

@end
