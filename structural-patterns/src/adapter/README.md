# 🛠 Adapter Pattern (어댑터 패턴)

어댑터 패턴은 **호환되지 않는 인터페이스를 변환하여** 기존 코드와 함께 동작할 수 있도록 도와주는 패턴입니다.  
핵심 아이디어는 **기존 객체를 래핑(Wrapping)하여 원하는 인터페이스로 변환**하는 것입니다.

래핑된 객체는 어댑터의 존재를 알지 못하며, 어댑터는 **인터페이스 변환 역할**만 수행합니다.

---

## 📌 구조 (Types of Adapter)

### 🔹 1. 객체 어댑터 (Object Adapter)

**✅ 구현 방식**: 객체 합성 (Composition) 원칙을 사용  
**✅ 특징**:

- 어댑터가 대상 인터페이스를 **구현**하고,
- 변환할 객체를 **래핑(Wrapping)** 하여 동작

**✅ 장점**:

- 기존 클래스를 변경하지 않고 확장 가능
- 유연한 설계 (런타임에 다른 객체를 주입 가능)
- 대부분의 프로그래밍 언어에서 사용 가능

**📌 예제 (Java)**

```java
class Target {
    void request() {
        System.out.println("Target 요청 처리");
    }
}

class Adaptee {
    void specificRequest() {
        System.out.println("Adaptee의 특정 요청 처리");
    }
}

// ✅ 객체 어댑터 (Composition 활용)
class ObjectAdapter extends Target {
    private Adaptee adaptee;

    public ObjectAdapter(Adaptee adaptee) {
        this.adaptee = adaptee;
    }

    @Override
    void request() {
        adaptee.specificRequest(); // 기존 기능을 변환하여 호출
    }
}
```

### 🔹 2. 클래스 어댑터 (Class Adapter)

**✅ 구현 방식**: 다중 상속 (Multiple Inheritance) 사용  
**✅ 특징**:

- 어댑터가 대상 인터페이스와 기존 클래스 모두를 상속
- C++처럼 다중 상속을 지원하는 언어에서만 가능

**✅ 장점**:

- 실행 속도가 빠름 (런타임 객체 생성 없이 직접 호출)
- 코드가 간결함

**🚨 단점**:

- 다중 상속이 필요한 구조로 인해, 유연성이 낮음
- 일부 프로그래밍 언어에서는 지원되지 않음

**📌 예제 (C++)**

```cpp
class Target {
public:
    virtual void request() {
        cout << "Target 요청 처리" << endl;
    }
};

class Adaptee {
public:
    void specificRequest() {
        cout << "Adaptee의 특정 요청 처리" << endl;
    }
};

// ✅ 클래스 어댑터 (다중 상속 활용)
class ClassAdapter : public Target, private Adaptee {
public:
    void request() override {
        specificRequest();  // 기존 기능을 변환하여 호출
    }
};
```

## 🚀 어댑터 패턴 적용 방법 (When to Use Adapter?)

- ✅ 기존 클래스를 사용하고 싶지만 인터페이스가 호환되지 않을 때
- ✅ 부모 클래스에 추가할 수 없는 기능이 필요할 때
- ✅ 여러 기존 자식 클래스를 재사용하려 할 때

## 🎯 어댑터 패턴의 장점 (Advantages)

- ✔ 기존 클래스를 수정하지 않고도 새로운 기능 추가 가능
- ✔ 유지보수성이 높아짐 (OCP 원칙 준수)
- ✔ 데코레이터 패턴과 유사하지만, 목적이 인터페이스 변환

## 📊 객체 어댑터 vs 클래스 어댑터 비교

| 타입              | 구현 방식                        | 장점                   | 단점                               |
| ----------------- | -------------------------------- | ---------------------- | ---------------------------------- |
| **객체 어댑터**   | 객체 합성 (Composition)          | 유연하고 유지보수 쉬움 | 성능이 다소 떨어질 수 있음         |
| **클래스 어댑터** | 다중 상속 (Multiple Inheritance) | 빠르고 코드 간결       | 다중 상속이 필요하여 유연성이 낮음 |

## 💡 정리 (Conclusion)

어댑터 패턴은 서로 호환되지 않는 클래스들이 함께 동작할 수 있도록 해주는 강력한 디자인 패턴입니다.
특히, 레거시 시스템을 유지하면서도 새로운 코드와 연동해야 할 때 매우 유용합니다.

이 패턴을 활용하면 기존 코드를 건드리지 않고 새로운 기능을 추가할 수 있어,
유지보수성과 확장성이 높은 코드를 만들 수 있습니다! 🚀
