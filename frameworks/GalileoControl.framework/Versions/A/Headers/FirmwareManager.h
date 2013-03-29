//  Created by Chris Harding on 11/27/12.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** The FirmwareManager object allows you to update Galileo's firmware. You can access the instance through the `firmwareManager` property of the `Galileo` singleton instance.
 */

#import <Foundation/Foundation.h>

@interface FirmwareManager : NSObject

///---------------------------------------------------------------------------------------
/// @name Checking for firmware updates
///---------------------------------------------------------------------------------------

/** Check for a new version of Galileo's firmware.
  @param completionBlock Code block that is to be called when the update check is complete.
 @discussion  This requires an internet connection and for Galileo to be connected. If a firmware update is available then the user will be prompted to install it using the motrr LAUNCH app. If the motrr LAUNCH app isn't installed, they will instead be prompted to install it from the Apple App Store. Otherwise, the motrr LAUNCH app will be launched and the user will be taken through the steps required to update Galileo's firmware.
 
    Note that if the user launches either the Apple App Store or the motrr LAUNCH app then there is no guarantee that completionBlock will be called. 
 */
- (void) checkForUpdateOnCompletion:(void (^)()) completionBlock;



@end
