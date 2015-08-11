/*****************************************************************************
 * SharedDialogs.h: MacOS X interface module
 *****************************************************************************
 * Copyright (C) 2012 Felix Paul Kühne
 * $Id$
 *
 * Authors: Felix Paul Kühne <fkuehne -at- videolan -dot- org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#import <Cocoa/Cocoa.h>

@interface VLCTextfieldPanelController : NSWindowController

@property (weak) IBOutlet NSTextField *titleLabel;
@property (weak) IBOutlet NSTextField *subtitleLabel;
@property (weak) IBOutlet NSTextField *textField;
@property (weak) IBOutlet NSButton *cancelButton;
@property (weak) IBOutlet NSButton *okButton;

@property (readwrite, assign) NSString *title;
@property (readwrite, assign) NSString *subTitle;
@property (readwrite, assign) NSString *OKButtonLabel;
@property (readwrite, assign) NSString *CancelButtonLabel;

/**
 * Completion handler for textfield panel
 * \param returnCode Result from panel. Can be NSOKButton or NSCancelButton.
 * \param resultingText Resulting text string entered in panel.
 */
typedef void(^TextfieldPanelCompletionBlock)(NSInteger returnCode, NSString *resultingText);

/**
 * Shows the panel as a modal dialog with window as its owner.
 * \param window Parent window for the dialog.
 * \param handler Completion block.
 */
- (void)runModalForWindow:(NSWindow *)window completionHandler:(TextfieldPanelCompletionBlock)handler;

- (IBAction)windowElementAction:(id)sender;

@end


@interface VLCPopupPanelController : NSWindowController

@property (weak) IBOutlet NSTextField *titleLabel;
@property (weak) IBOutlet NSTextField *subtitleLabel;
@property (weak) IBOutlet NSPopUpButton *popupButton;
@property (weak) IBOutlet NSButton *cancelButton;
@property (weak) IBOutlet NSButton *okButton;

@property (readwrite, assign) NSString *title;
@property (readwrite, assign) NSString *subTitle;
@property (readwrite, assign) NSString *OKButtonLabel;
@property (readwrite, assign) NSString *CancelButtonLabel;
@property (readwrite, assign) NSArray *popupButtonContent;
@property (readwrite, assign) id target;
@property (readonly) NSUInteger currentItem;

- (void)runModalForWindow:(NSWindow *)window;

- (IBAction)windowElementAction:(id)sender;

@end

@protocol VLCPopupPanelController <NSObject>
@optional
- (void)panel:(VLCPopupPanelController *)panel returnValue:(NSUInteger)value item:(NSUInteger)item;
@end
