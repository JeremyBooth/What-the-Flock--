uniform mat4 projectionMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ModelMatrix;


varying vec3 fragmentNormal;

void main(void)
{
	fragmentNormal = (ViewMatrix*ModelMatrix*vec4(gl_Normal, 0.0)).xyz;
	gl_Position = projectionMatrix*ViewMatrix*ModelMatrix*gl_Vertex;
}
