                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      unsigned int format,
                         unsigned int type,
                         int textureSize[3],
                         int componentSize);

  void SlabsFromDatasetToIndex(double slabsDataSet[6],
                               double slabsPoints[6]);

  void SlabsFromIndexToDataset(double slabsPoints[6],
                               double slabsDataSet[6]);

  const char *GetEnabledString(unsigned char value);
  void GetOpenGLState();

  void DebugDisplayBox(vtkPolyData *box);

  void UpdateNoiseTexture();

  // Description:
  // Compute how each axis of a cell is projected on the viewport in pixel.
  // This requires to have information about the camera and about the volume.
  // It set the value of IgnoreSampleDistancePerPixel to true in case of
  // degenerated case (axes aligned with the view).
  double ComputeMinimalSampleDistancePerPixel(vtkRenderer *renderer,
                                              vtkVolume *volume);

  // Description:
  // Return how much the dataset has to be reduced in each dimension to
  // fit on the GPU. If the value is 1.0, there is no need to reduce the
  // dataset.
  // \pre the calling thread has a current OpenGL context.
  // \pre mapper_supported: IsRenderSupported(renderer->GetRenderWindow(),0)
  // The computation is based on hardware limits (3D texture indexable size)
  // and MaxMemoryInBytes.
  // \post valid_i_ratio: ratio[0]>0 && ratio[0]<=1.0
  // \post valid_j_ratio: ratio[1]>0 && ratio[1]<=1.0
  // \post valid_k_ratio: ratio[2]>0 && ratio[2]<=1.0
  virtual void GetReductionRatio(double ratio[3]);

  int NumberOfCroppingRegions;

  // World coordinates of each corner of the dataset.
  double BoundingBox[8][3];

  // Used during the clipping process.
  vtkPolyData *PolyDataBoundingBox;
  vtkPlaneCollection *Planes;
  vtkPlane *NearPlane;

  vtkClipConvexPolyData *Clip;
  vtkMatrix4x4 *InvVolumeMatrix;

  vtkDensifyPolyData *Densify;

  int OpenGLObjectsCreated;
  int NumberOfFrameBuffers;

  unsigned int FrameBufferObject;
  unsigned int DepthRenderBufferObject;

  // 3D scalar texture +1D color+1D opacity+2D grabbed depth buffer
  // +1 2D colorbuffer.
  unsigned int TextureObjects[5];
  // used in MIP Mode (2 needed for ping-pong technique)
  unsigned int MaxValueFrameBuffer;
  unsigned int MaxValueFrameBuffer2;
  int ReducedSize[2];

  vtkPolyData *ClippedBoundingBox;

  int LastSize[2];

  double ReductionFactor;

  // Supported extensions
  // List of unsupported required extensions. Pimpl.
  vtkUnsupportedRequiredExtensionsStringStream *UnsupportedRequiredExtensions;
  int LoadExtensionsSucceeded;

  int Supports_GL_ARB_texture_float;
  int SupportsPixelBufferObjects;

  vtkTimeStamp DataBufferTime;

  // Matrices used in internal computation. As a member variable,
  // only one memory allocation is performed.
  vtkMatrix4x4 *TempMatrix[3];

  double TableRange[2];

  // Final string to send to the GPU as the fragment program source code.
//  char *FragmentCode;
//  int FragmentCodeCapacity;

  int ErrorLine;
  int ErrorColumn;
  char *ErrorString;

  // Store the last projection an raycast method in order to not rebuild
  // the fragment code at every call.
  int LastParallelProjection;
  int LastRayCastMethod;
  int LastCroppingMode;
  int LastComponent;
  int LastShade;

  vtkImageData *SmallInput;
  vtkTimeStamp SmallInputBuildTime;

  // Description:
  // Build the fragment shader program that scale and bias a texture
  // for window/level purpose.
  void BuildScaleBiasProgram(vtkRenderWindow *w);

#if 0
  vtkIdType LoadedExtent[6];
  double LoadedBounds[6];
  vtkTimeStamp LoadedScalarTime;
  int LoadedCellFlag; // point data or cell data (or field data, not handled) ?
#endif

  unsigned int SavedFrameBuffer; // some offscreen mode use a framebuffer too.

  vtkTessellatedBoxSource *BoxSource;

  float *NoiseTexture;
  int NoiseTextureSize; // size of one dimension.
  unsigned int NoiseTextureId; // GLuint

  bool IgnoreSampleDistancePerPixel;

  vtkMapDataArrayTextureId *ScalarsTextures; // need a list for AMR mode.
  vtkMapMaskTextureId *MaskTextures; // need a list for AMR mode.

  vtkRGBTable *RGBTable;
  vtkRGBTable *Mask1RGBTable;
  vtkRGBTable *Mask2RGBTable;

  vtkOpacityTables *OpacityTables;

  vtkKWScalarField *CurrentScalar;
  vtkKWMask *CurrentMask;

  float ActualSampleDistance;

  double LastProgressEventTime; // initial value is 0.0. Expressed in seconds.

  bool PreserveOrientation;
  
  vtkShaderProgram2 *Program;
  vtkShader2 *Main;
  vtkShader2 *Projection;
  vtkShader2 *Trace;
  vtkShader2 *CroppingShader;
  vtkShader2 *Component;
  vtkShader2 *Shade;

  // Internal Variable used to keep track of whether or render window's size
  // changed and therefore we need re-allocation.
  bool        SizeChanged;

  vtkShaderProgram2 *ScaleBiasProgram;

private:
  vtkOpenGLGPUVolumeRayCastMapper(const vtkOpenGLGPUVolumeRayCastMapper&);  // Not implemented.
  void operator=(const vtkOpenGLGPUVolumeRayCastMapper&);  // Not implemented.
};

#endif
