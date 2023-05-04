template <typename T>
class SmartPointer {
   protected:
    T* ptr;
    unsigned* refCount;

   public:
    SmartPointer(T* ptr) : ptr(ptr) {
        refCount = new unsigned;
        *refCount = 1;
    }

    SmartPointer(SmartPointer<T>& sptr) {
        ptr = sptr.ptr;
        refCount = sptr.refCount;
        ++(*refCount);
    }

    SmartPointer<T>& operator=(SmartPointer<T>& sptr) {
        if (this == &sptr) return *this;

        if (*refCount > 0) Remove();

        ptr = sptr.ptr;
        refCount = sptr.refCount;
        ++(*refCount);
        return *this;
    }

    ~SmartPointer() { Remove(); }

    T GetValue() { return *ptr; }

    T* Get() { return ptr; }

   protected:
    void Remove() {
        --(*refCount);
        if (*refCount == 0) {
            delete ptr;
            delete refCount;
            ptr = nullptr;
            refCount = nullptr;
        }
    }
};
