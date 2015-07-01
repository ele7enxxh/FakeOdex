# FakeOdex
modify field(modWhen, crc) in android odex file;安卓APP“寄生兽”漏洞

# Bug Info
http://drops.wooyun.org/papers/6910
http://secauo.com/Android%E6%BC%8F%E6%B4%9E%E5%88%86%E6%9E%90/%E5%85%B3%E4%BA%8E360%E6%89%80%E8%B0%93%E7%9A%84%E8%B6%85%E7%BA%A7%E5%AE%89%E5%8D%93%E6%BC%8F%E6%B4%9E%E2%80%9C%E5%AF%84%E7%94%9F%E5%85%BD%E2%80%9D.html

# Build
```gcc fakeOdex.c -o fakeOdex```

# Usage
```fakeOdex orig.odex fake.odex```
