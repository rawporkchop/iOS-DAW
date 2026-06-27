//
//  DAWApp.swift
//  DAW
//
//  Created by Oliver Larsson on 6/20/26.
//

import SwiftUI
import AVFoundation

@main
struct DAWApp: App {
    @UIApplicationDelegateAdaptor(AppDelegate.self) var delegate

    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}

class AppDelegate: NSObject, UIApplicationDelegate {
    
    func application(_ application: UIApplication,
                     didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        let session = AVAudioSession.sharedInstance()
        try? session.setCategory(.playAndRecord, mode: .default)
        try? session.setActive(true)
        
        DispatchQueue.main.async {
            AudioEngine_start()
        }
        return true
    }
}
