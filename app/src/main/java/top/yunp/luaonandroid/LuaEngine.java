package top.yunp.luaonandroid;

public class LuaEngine {
    static {
        System.loadLibrary("native-lib");
    }

    private static native long luaNewstate();

    private static native void luaClose(long pointer);

    private static native void luaLOpenLibs(long luaState);

    private static native void luaDoString(long luaState, String luaScriptString);

    private static native void luaGetGlobal(long luaState, String name);

    private static native String luaToString(long luaState, int position);

    private static native long luaToLong(long luaState, int poistion);

    private long luaStatePointer = 0;

    public LuaEngine() {
        luaStatePointer = luaNewstate();
        luaLOpenLibs(luaStatePointer);
    }

    public void doString(String script) {
        luaDoString(luaStatePointer, script);
    }

    public String getGlobalString(String name) {
        luaGetGlobal(luaStatePointer, name);
        return luaToString(luaStatePointer, -1);
    }

    public long getGlobalLong(String name) {
        luaGetGlobal(luaStatePointer, name);
        return luaToLong(luaStatePointer, -1);
    }

    public void dispose() {
        if (luaStatePointer != 0) {
            luaClose(this.luaStatePointer);
        }
    }
}
