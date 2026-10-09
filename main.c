#include <Carbon/Carbon.h>
#include <string.h>

int main(int argc, char *argv[]) {
        const char *id = "com.apple.keylayout.ABC";

        if (argc >= 3 && strcmp(argv[1], "-i") == 0) {
                id = argv[2];
        }

        CFStringRef source_id = CFStringCreateWithCString(
            kCFAllocatorDefault, id, kCFStringEncodingUTF8);

        if (source_id == NULL) {
                return 0;
        }

        const void *keys[] = {kTISPropertyInputSourceID};
        const void *values[] = {source_id};

        CFDictionaryRef filter = CFDictionaryCreate(
            kCFAllocatorDefault, keys, values, 1,
            &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);

        if (filter != NULL) {
                CFArrayRef sources = TISCreateInputSourceList(filter, false);

                if (sources != NULL) {
                        if (CFArrayGetCount(sources) > 0) {
                                TISSelectInputSource(
                                    (TISInputSourceRef)CFArrayGetValueAtIndex(
                                        sources, 0));
                        }

                        CFRelease(sources);
                }

                CFRelease(filter);
        }

        CFRelease(source_id);
        return 0;
}
