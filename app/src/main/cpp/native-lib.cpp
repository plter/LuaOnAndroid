#include <jni.h>
#include "lua.hpp"

extern "C"
JNIEXPORT jlong JNICALL
Java_top_yunp_luaonandroid_LuaEngine_luaNewstate(JNIEnv *env, jclass type) {
    return reinterpret_cast<jlong>(luaL_newstate());
}extern "C"
JNIEXPORT void JNICALL
Java_top_yunp_luaonandroid_LuaEngine_luaClose(JNIEnv *env, jclass type, jlong pointer) {
    lua_close(reinterpret_cast<lua_State *>(pointer));
}extern "C"
JNIEXPORT void JNICALL
Java_top_yunp_luaonandroid_LuaEngine_luaLOpenLibs(JNIEnv *env, jclass type, jlong luaState) {
    luaL_openlibs(reinterpret_cast<lua_State *>(luaState));
}extern "C"
JNIEXPORT void JNICALL
Java_top_yunp_luaonandroid_LuaEngine_luaDoString(JNIEnv *env, jclass type, jlong luaState,
                                                 jstring luaScriptString_) {
    const char *luaScriptString = env->GetStringUTFChars(luaScriptString_, 0);
    luaL_dostring(reinterpret_cast<lua_State *>(luaState), luaScriptString);
    env->ReleaseStringUTFChars(luaScriptString_, luaScriptString);
}extern "C"
JNIEXPORT void JNICALL
Java_top_yunp_luaonandroid_LuaEngine_luaGetGlobal(JNIEnv *env, jclass type, jlong luaState,
                                                  jstring name_) {
    const char *name = env->GetStringUTFChars(name_, 0);
    lua_getglobal(reinterpret_cast<lua_State *>(luaState), name);
    env->ReleaseStringUTFChars(name_, name);
}extern "C"
JNIEXPORT jstring JNICALL
Java_top_yunp_luaonandroid_LuaEngine_luaToString(JNIEnv *env, jclass type, jlong luaState,
                                                 jint position) {
    const char *returnValue = lua_tostring(reinterpret_cast<lua_State *>(luaState), position);
    return env->NewStringUTF(returnValue);
}extern "C"
JNIEXPORT jlong JNICALL
Java_top_yunp_luaonandroid_LuaEngine_luaToLong(JNIEnv *env, jclass type, jlong luaState,
                                               jint poistion) {
    return lua_tointeger(reinterpret_cast<lua_State *>(luaState), poistion);
}