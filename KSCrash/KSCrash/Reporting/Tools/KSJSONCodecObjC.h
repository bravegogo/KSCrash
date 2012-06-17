//
//  KSJSONCodecObjC.h
//
//  Created by Karl Stenerud on 12-01-08.
//
//  Copyright (c) 2012 Karl Stenerud. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall remain in place
// in this source code.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//


#import <Foundation/Foundation.h>


/** Optional behavior when encoding JSON data */
typedef enum
{
    /** Indent 4 spaces per object/array level */
    KSJSONEncodeOptionPretty = 1,
    
    /** Sort object contents by key name */
    KSJSONEncodeOptionSorted = 2,
} KSJSONEncodeOption;


/** Optional behavior when decoding JSON data */
typedef enum
{
    /** Normally, null elements get stored as [NSNull null].
     * If this option is set, do not store anything when a null element is
     * encountered inside an array.
     */
    KSJSONDecodeOptionIgnoreNullInArray = 1,
    
    /** Normally, null elements get stored as [NSNull null].
     * If this option is set, do not store anything when a null element is
     * encountered inside an object.
     */
    KSJSONDecodeOptionIgnoreNullInObject = 2,
    
    /** Convenience enum to ignore nulls in arrays and objects. */
    KSJSONDecodeOptionIgnoreAllNulls = 3,
} KSJSONDecodeOption;


/**
 * Encodes and decodes UTF-8 JSON data.
 */
@interface KSJSONCodec : NSObject

/** Encode an object to JSON data.
 *
 * @param object The array or dictionary to encode.
 *
 * @param options Options for how to encode the data.
 *
 * @param error Place to store any error that occurs (nil = ignore).
 *
 * @return The encoded UTF-8 JSON data or nil if an error occurred.
 */
+ (NSData*) encode:(id) object
           options:(KSJSONEncodeOption) options
             error:(NSError**) error;

/** Decode JSON data to an object.
 *
 * @param JSONData The UTF-8 data to decode.
 *
 * @param options Options for how to decode the data.
 *
 * @param error Place to store any error that occurs (nil = ignore).
 *
 * @return The decoded object or nil if an error occurred.
 */
+ (id) decode:(NSData*) JSONData
      options:(KSJSONDecodeOption) options
        error:(NSError**) error;

@end