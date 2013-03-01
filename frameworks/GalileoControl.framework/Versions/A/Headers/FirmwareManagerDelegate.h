//  Created by Chris Harding on 11/27/12.
//  Copyright (c) 2012 MOTRR LLC. All rights reserved.
//

/** This protocol defines an interface for delegates of a `FirmwareManager` object to be notified of the result of a firmware update check and the result of a firmware update application.
 */

#import <Foundation/Foundation.h>

@protocol FirmwareManagerDelegate <NSObject>

///---------------------------------------------------------------------------------------
/// @name Delegate Methods
///---------------------------------------------------------------------------------------

@required

/** Notifies the delegate if a firmware update is or isn't available for the connected accessory.
 @param isUpdateAvailable True if a firmware version more recent that the current version was found and downloaded succesfully. False otherwise.
 */
- (void) checkForUpdateComplete: (BOOL) isUpdateAvailable;

/** Notifies the delegate if the firmware update for the connected accessory was performed succesfuly.
  @param wasUpdateSuccessful True if a firmware update was successfully applied. False otherwise.
 */
- (void) performUpdateComplete: (BOOL) wasUpdateSuccessful;


@end
