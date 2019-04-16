import os

path = "/auto/ios-snaps/snaps/flo_dsgs7/ios/sys/src-galaxy"

folders = []

for r, d, f in os.walk(path):
    for folder in d:
        folders.append(os.path.join(r, folder))

for f in folders:
    print(f)

