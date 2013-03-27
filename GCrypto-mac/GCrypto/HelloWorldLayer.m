//
//  HelloWorldLayer.m
//  GCrypto
//
//  Created by Ghost on 12-8-20.
//  Copyright __MyCompanyName__ 2012年. All rights reserved.
//


// Import the interfaces
#import "HelloWorldLayer.h"

#include "TEAManager.h"
#include "AESManager.h"

// HelloWorldLayer implementation
@implementation HelloWorldLayer

+(CCScene *) scene
{
	// 'scene' is an autorelease object.
	CCScene *scene = [CCScene node];
	
	// 'layer' is an autorelease object.
	HelloWorldLayer *layer = [HelloWorldLayer node];
	
	// add layer as a child to scene
	[scene addChild: layer];
	
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
-(id) init
{
	// always call "super" init
	// Apple recommends to re-assign "self" with the "super" return value
	if( (self=[super init]) ) {
		
		// create and initialize a Label
		CCLabelTTF *label = [CCLabelTTF labelWithString:@"Hello World" fontName:@"Marker Felt" fontSize:64];

		// ask director for the window size
		CGSize size = [[CCDirector sharedDirector] winSize];
	
		// position the label on the center of the screen
		label.position =  ccp( size.width /2 , size.height/2 );
		
		// add the label as a child to this Layer
		[self addChild: label];
	}
    
//    NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:[[CCFileUtils sharedFileUtils] fullPathFromRelativePath:@"abc.plist"]];
//    
//    NSArray *array = [dict objectForKey:@"array"];
//    
//    for (int i = 0 ; i < array.count ; ++i)
    {
//        NSString *string = [array objectAtIndex:i];
        NSString *string = @"123321.txt";
        
        NSData *data = [NSData dataWithContentsOfFile:[[CCFileUtils sharedFileUtils] fullPathFromRelativePath:string]];
        
        crypto_cstring tmp = xxteaEncrypt([data bytes], data.length, "fi293nofg0ajdfj2", 16);
        
        data = [NSData dataWithBytes:tmp.context length:tmp.length];
        
        string = [[@"/girlmaster/" stringByAppendingString:string] stringByAppendingString:@"x"];
        
        NSLog(@"%@ is Encrypt done.",string);
        
        [data writeToFile:string atomically:YES];
    }
    
    
    
    
//    array = [dict objectForKey:@"array"];
//    
//    for (int i = 0 ; i < array.count ; ++i)
    {
//        NSString *string = [array objectAtIndex:i];
        NSString *string = @"123321.txt";
        
        NSString *string1 = [[@"/girlmaster/" stringByAppendingString:string] stringByAppendingString:@"x"];
        
        NSData *data = [NSData dataWithContentsOfFile:string1];
        
        crypto_cstring tmp = xxteaDecrypt([data bytes], data.length, "fi293nofg0ajdfj2", 16);
        
        data = [NSData dataWithBytes:tmp.context length:tmp.length];
        
        string = [@"/girlmaster1/" stringByAppendingString:string];
        
        NSLog(@"%@ is Decrypt done.",string);
        
        [data writeToFile:string atomically:YES];
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
	return self;
}

// on "dealloc" you need to release all your retained objects
- (void) dealloc
{
	// in case you have something to dealloc, do it in this method
	// in this particular example nothing needs to be released.
	// cocos2d will automatically release all the children (Label)
	
	// don't forget to call "super dealloc"
	[super dealloc];
}
@end
