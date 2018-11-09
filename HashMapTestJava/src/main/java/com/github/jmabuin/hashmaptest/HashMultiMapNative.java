package com.github.jmabuin.hashmaptest;

import cz.adamh.utils.NativeUtils;

import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by chema on 3/23/17.
 */
public class HashMultiMapNative implements Serializable {

    public HashMultiMapNative() {

        try {
            NativeUtils.loadLibraryFromJar("/libhashmultimap.so");
            System.out.println("Native library loaded");
        } catch (IOException e) {
            e.printStackTrace();
            System.err.println("Error!! Could not load the native library!! : "+e.getMessage());
            System.exit(1);
        }
        catch (Exception e) {
            e.printStackTrace();
            System.err.println("Error!! Could not load the native library!! : "+e.getMessage());
            System.exit(1);
        }

        this.init();
    }

    private native int init();
    public native int add(int key, int value1, int value2);
    public native int[] get(int key);
    public native int size();

    public void add(int key, Location location) {

        this.add(key, location.targetId, location. windowId);

    }

    public List<Location> get_list(int key) {

        int[] rec_values = this.get(key);

        List<Location> returned_values = new ArrayList<>();

        for ( int i = 0; i< rec_values.length; i+=2) {

            Location new_location = new Location(rec_values[i], rec_values[i+1]);
            returned_values.add(new_location);
        }

        return returned_values;

    }



}
