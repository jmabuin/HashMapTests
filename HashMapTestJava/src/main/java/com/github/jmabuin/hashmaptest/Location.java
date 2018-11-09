package com.github.jmabuin.hashmaptest;
import java.io.Serializable;

/**
 * Created by jabuinmo on 31.01.17.
 */
//public class LocationBasic implements Serializable, Comparable<Location>{
public class Location {

	public int targetId;
	public int windowId;

	public Location(int targetId, int windowId) {
		//public Location(int targetId, int windowId) {

		this.targetId = targetId;
		this.windowId = windowId;

		//this.header = header;
		//this.taxid = taxid;
	}



}
