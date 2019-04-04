//
//  SpeechToTextYWS.h
//  MicrosoftSpeechX
//
//  Created by Yoseph Joyz on 04/04/19.
//  Copyright © 2019 Joyz. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ErrorType) {
  COULD_NOT_LOAD_SPEECH_CONFIG,
  SPEECH_CONFIG_NOT_READY,
  RECOGNIZER_SPEECH_NOT_READY,
  COULD_NOT_CREATE_RECOGNIZER
};

@protocol SpeechToTextXProtocol
@required
-(void) errorHandler:(ErrorType)type;
-(void) onPartialResponse:(NSString*)text;
-(void) onFinishedResponse:(NSString*)text score:(NSString*)confidence;
-(void) onNoResponse;
@end

@interface SpeechToTextYWS : NSObject

@property (nonatomic, weak) id<SpeechToTextXProtocol> delegate;

-(void)startConfig:(NSString *) speechKey
     regionService:(NSString *) regionService;

-(void)initiateRecognizer;
-(void)startRecognize;
-(void)stopRecognize;

@end

NS_ASSUME_NONNULL_END
