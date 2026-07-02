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

// Audio Initialization Procedure
// Sets up correct iOS bitrate, sample rate, permissions
class AppDelegate: NSObject, UIApplicationDelegate {

    let runtime = AudioRuntime()
    
    func application(_ application: UIApplication,
                     didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        setupAudioSession()
        
        NotificationCenter.default.addObserver(self,
            selector: #selector(handleInterruption),
            name: AVAudioSession.interruptionNotification,
            object: nil)
        
        return true
    }

    func setupAudioSession() {
        let session = AVAudioSession.sharedInstance()
        try? session.setCategory(.playAndRecord, mode: .default, options: [.defaultToSpeaker])
        try? session.setPreferredIOBufferDuration(0.005)
        try? session.setPreferredSampleRate(44100)
        try? session.setActive(true)

        AVAudioApplication.requestRecordPermission { granted in
            DispatchQueue.main.async {
                if granted { runtime.startEngine() }
            }
        }
    }

    @objc func handleInterruption(_ notification: Notification) {
        guard let info = notification.userInfo,
              let typeValue = info[AVAudioSessionInterruptionTypeKey] as? UInt,
              let type = AVAudioSession.InterruptionType(rawValue: typeValue) else { return }

        if type == .ended {
            try? AVAudioSession.sharedInstance().setActive(true)
            runtime.restart()
        }
    }
}
