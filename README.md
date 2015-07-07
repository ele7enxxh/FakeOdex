# FakeOdex
modify field(modWhen, crc) in android odex file;安卓APP“寄生兽”漏洞

# Bug Info
http://drops.wooyun.org/papers/6910
http://secauo.com/Exaggerated-Android-Vulnerability-Parasyte.html

# Build
```gcc fakeOdex.c -o fakeOdex```

# Usage
```fakeOdex orig.odex fake.odex```
