//  Created by Chris Harding on 11/27/12.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** The FirmwareManager object allows you to update Galileo's firmware. You can access the instance through the `firmwareManager` property of the `Galileo` singleton instance.
 */

#import <Foundation/Foundation.h>
#import "FirmwareManagerDelegate.h"

@class MTFirmwareVersion;

@interface FirmwareManager : NSObject


///---------------------------------------------------------------------------------------
/// @name Setting and Getting the Delegate
///---------------------------------------------------------------------------------------

/** The delegate of the FirmwareManager object.
 @discussion  The delegate must adopt the FirmwareManagerDelegate protocol. The delegate is not retained.
 */
@property (nonatomic, assign) id<FirmwareManagerDelegate> delegate;


///---------------------------------------------------------------------------------------
/// @name Checking for firmware updates
///---------------------------------------------------------------------------------------

/** Check for a new version of Galileo's firmware.
 @discussion  This requires an internet connection and for Galileo to be connected. If a firmware update is available it will be downloaded and prepared for installation. The result of the update check can be obtained by implementing the `FirmwareManagerDelegate` protocol and setting the delegate property.
 */
- (void) checkForUpdate;


///---------------------------------------------------------------------------------------
/// @name Applying firmware updates
///---------------------------------------------------------------------------------------

/** Prompt user to install a firmware update to Galileo.
 @discussion  This method requires `checkForNewVersion` to have been called and for an update to be available, as indicated by the `newUpdateAvailable:` method being called on the delegate property. This will prompt the user to install the firmware update. This will halt all Galileo motion control until the update process is either complete or has been cancelled. It is vitally important that the user does not disconect the phone from Galileo whilst updating the firmware as this could damage Galileo irrecoverably.
 */
- (void) promptUserToInstallUpdate;

//- (void) getAvailableFirmware;

//- (void) forceFirmwareUpdate: (FirmwareVersion*) firmwareVersion;



@end
