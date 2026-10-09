// defaults read ~/Library/Preferences/com.apple.HIToolbox.plist AppleEnabledInputSources
import Carbon

let sources = TISCreateInputSourceList(nil, false)!.takeRetainedValue() as! [TISInputSource]

for source in sources {
    let id = TISGetInputSourceProperty(source, kTISPropertyInputSourceID)
        .map { Unmanaged<CFString>.fromOpaque($0).takeUnretainedValue() as String } ?? ""

    let name = TISGetInputSourceProperty(source, kTISPropertyLocalizedName)
        .map { Unmanaged<CFString>.fromOpaque($0).takeUnretainedValue() as String } ?? ""

    print("\(id)\t\(name)")
}
