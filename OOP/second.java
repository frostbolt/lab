class Point {
	public float x;
	public float y;

	Point(float X, float Y, float Z) {
		x = X;
		y = Y;
		z = Z;
	}
	public String toString() {
		return "("+x+","+y+","+z+")";
	}
	public void move(float dx, float dy, float dz){
		x+=dx;
		y+=dy;
		z+=dz;
	}
}

class Circle {
	private Point center;
	private float radius;

	Circle(Point C, float R) {
		center = C;
		radius = R;
	}

	public String toString() {
		return "("+x+","+y+","+z+")";
	}

	public float area() {
		return 3.14159265*radius*radius;
	}

	public void move(float dx, float dy, float dz) {
		center.move(dx,dy,dz);
	}

}

class Sphere extends Circle {
	
	Sphere(Point C, float R) {
		center = C;
		radius = R;
	}

	public String toString() {
		return "(x-"+center.x+")^2 + (y-"+center.y+")^2 + (z-"+center.z+")^2 <= "+radius*radius;
	}

	public float vol() {
		return 4/3*3.14159265*radius*radius*radius;
	}

	public float area() {
		return 4*3.14159265*radius*radius;
	}

	public void resize(float r) {
		if (r>0) {
			radius = r;
		}
	}
}

class Cylinder extends Circle {

	Cylinder(Point C, float R, float H) {
		center = C;
		radius = R;
		height = H;
	}

	public String toString() {
		return "(x-"+center.x+")^2 + (y-"+center.y+")^2 <= "+radius*radius+",\n"+
				+center.z+"<= z <= "+ height +".";
	}

	public float vol() {
		return 3.14159265*radius*radius*height;
	}

	public float area() {
		return 2*3.14159265*radius*(height+radius);
	}

	public void resize(float r, float h) {
		if (r>0 or r == null) {
			radius = (r)?r:radius;
		}
		if (h>0 or h == null) {
			height = (h)?h:height;
		}
	}

}

class Cone extends Circle {
	Cone(Point C, float R, float H) {
		center = C;
		radius = R;
		height = H;
	}

	public String toString() {
		return "(x-"+center.x+")^2 + (y-"+center.y+")^2 <= "+radius*radius+",\n"+ //как описать?
				"z >= 0.";
	}

	public float vol() {
		return 3.14159265*radius*radius*height/3;
	}

	public float area() {
		return 3.14159265*radius*(height+radius);
	}

	public void resize(float r, float h) {
		if (r>0 or r == null) {
			radius = (r)?r:radius;
		}
		if (h>0 or h == null) {
			height = (h)?h:height;
		}
	}

}