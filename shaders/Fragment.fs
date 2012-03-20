
/// @brief[in] the vertex normal
varying vec3 fragmentNormal;


void main ()
{
  // set the output colour to black
  vec4 colour= vec4(0.0);
  // normalize the vertex normal
  vec3 N = normalize(fragmentNormal);
  // The Light source vector
  vec3 L;
  // the Halfway vector (used for speed)
  vec3 H;
  // pre declare the colour contribution values
  vec4 ambient;
  vec4 diffuse;
  vec4 specular;


  // get the Light vector
  L = normalize(gl_LightSource[0].position.xyz);
  // get the halfway vector
  H = normalize(gl_LightSource[0].halfVector.xyz);
  // ambient just added
  ambient = gl_FrontMaterial.ambient *gl_LightSource[0].ambient;
  // calculate diffuse based on Lambert's law (L.N)
  diffuse = gl_FrontMaterial.diffuse  *gl_LightSource[0].diffuse * max(dot(L, N), 0.0);
  // calculate specular based on H.N^Shininess
  specular = gl_FrontMaterial.specular *gl_LightSource[0].specular * pow(max(dot(H, N), 0.0), gl_FrontMaterial.shininess);
  // combine contribution for the light
  colour+=ambient+diffuse+specular;
  // finally set the colour clamping between 0 and 1
  gl_FragColor = clamp(vec4(colour),0.0,1.0);

}
