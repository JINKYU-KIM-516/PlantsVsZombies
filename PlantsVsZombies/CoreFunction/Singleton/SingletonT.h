#pragma once
#include <windows.h>
#include <string>
#include <typeinfo> // typeid�� ���� �ʿ�

template <typename T>
class SingletonT
{
protected:
    SingletonT() = default;
    virtual ~SingletonT() = default;

    SingletonT(const SingletonT&) = delete;
    SingletonT& operator=(const SingletonT&) = delete;

private:
    static T* instance;

public:
    static T* GetI()
    {
        if (!instance)
        {
            instance = new T();
            static struct Deleter {
                ~Deleter() {
                    if (instance)
                    {
                        auto& id = typeid(instance);
                        WCHAR wstr[256];
                        int result = MultiByteToWideChar(CP_ACP, 0, id.name(), -1, wstr, _countof(wstr));
                        wsprintf(wstr, L"%s : �Ŵ��� �ڵ��Ҹ�1\n", wstr);
                        ::OutputDebugString(wstr);

                        delete instance;
                        instance = nullptr;
                    }
                }
            } deleter;
        }
        return instance;
    }
    static T& Instance()
    {
        if (!instance)
        {
            instance = new T();
            static struct Deleter {
                ~Deleter() {
                    if (instance) {
                        auto& id = typeid(instance);
                        WCHAR wstr[256];
                        int result = MultiByteToWideChar(CP_ACP, 0, id.name(), -1, wstr, _countof(wstr));
                        wsprintf(wstr, L"%s : �Ŵ��� �ڵ��Ҹ�2\n", wstr);
                        ::OutputDebugString(wstr);

                        delete instance;
                        instance = nullptr;
                    }
                }
            } deleter;
        }
        return *instance;
    }

    virtual void DestroyManager()
    {
        if (instance) {
            auto& id = typeid(instance);

            WCHAR wstr[256];
            int result = ::MultiByteToWideChar(CP_ACP, 0, id.name(), -1, wstr, _countof(wstr));

            wsprintf(wstr, L"%s : �Ŵ��� �����Ҹ�\n", wstr);
            ::OutputDebugString(wstr);

            delete instance;
            instance = nullptr;
        }
    }

    virtual void Initialize()
    {
        // �ʱ�ȭ �۾�
    }
};

template <typename T>
T* SingletonT<T>::instance = nullptr;
