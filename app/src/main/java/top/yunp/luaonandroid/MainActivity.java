package top.yunp.luaonandroid;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);

        LuaEngine le = new LuaEngine();
        le.doString("name=\"TOP YUNP\"\n" +
                "age=10");
        tv.setText(le.getGlobalString("name") + le.getGlobalLong("age"));
        le.dispose();
    }
}
