#include <bdn/init.h>
#include <bdn/android/JNativeRootView.h>

#include <bdn/java/Env.h>

#include <bdn/android/WindowCore.h>
#include <bdn/android/JContext.h>


extern "C" JNIEXPORT void JNICALL Java_io_boden_android_NativeRootView_created(JNIEnv* pEnv, jobject rawSelf )
{
    BDN_JNI_BEGIN(pEnv);

    bdn::android::WindowCore::_rootViewCreated( bdn::java::Reference::convertExternalLocal(rawSelf) );

    BDN_JNI_END;
}

extern "C" JNIEXPORT void JNICALL Java_io_boden_android_NativeRootView_disposed( JNIEnv* pEnv, jobject rawSelf)
{
    BDN_JNI_BEGIN(pEnv);

    bdn::android::WindowCore::_rootViewDisposed( bdn::java::Reference::convertExternalLocal(rawSelf) );

    BDN_JNI_END;
}


extern "C" JNIEXPORT void JNICALL Java_io_boden_android_NativeRootView_sizeChanged(JNIEnv* pEnv, jobject rawSelf, int newWidth, int newHeight)
{
    BDN_JNI_BEGIN(pEnv);

    bdn::android::WindowCore::_rootViewSizeChanged( bdn::java::Reference::convertExternalLocal(rawSelf), newWidth, newHeight );

    BDN_JNI_END;
}



extern "C" JNIEXPORT void JNICALL Java_io_boden_android_NativeRootView_configurationChanged(JNIEnv* pEnv, jobject rawSelf, jobject rawNewConfig)
{
    BDN_JNI_BEGIN(pEnv);

    bdn::android::JConfiguration newConfig(( bdn::java::Reference::convertExternalLocal(rawNewConfig) ));

    bdn::android::WindowCore::_rootViewConfigurationChanged( bdn::java::Reference::convertExternalLocal(rawSelf), newConfig );

    BDN_JNI_END;
}
