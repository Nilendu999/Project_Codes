                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    { return this->GetNumberOfObjectArrays(SIDE_SET); }
  const char* GetSideSetResultArrayName(int index)
    { return this->GetObjectArrayName(SIDE_SET, index); }
  int GetSideSetResultArrayStatus(const char* name)
    { return this->GetObjectArrayStatus(SIDE_SET, name); }
  void SetSideSetResultArrayStatus(const char* name, int flag)
    { this->SetObjectArrayStatus(SIDE_SET, name, flag); }
  
  int GetNumberOfEdgeSetResultArrays()
    { return this->GetNumberOfObjectArrays(EDGE_SET); }
  const char* GetEdgeSetResultArrayName(int index)
    { return this->GetObjectArrayName(EDGE_SET, index); }
  int GetEdgeSetResultArrayStatus(const char* name)
    { return this->GetObjectArrayStatus(EDGE_SET, name); }
  void SetEdgeSetResultArrayStatus(const char* name, int flag)
    { this->SetObjectArrayStatus(EDGE_SET, name, flag); }

  int GetNumberOfFaceSetResultArrays()
    { return this->GetNumberOfObjectArrays(FACE_SET); }
  const char* GetFaceSetResultArrayName(int index)
    { return this->GetObjectArrayName(FACE_SET, index); }
  int GetFaceSetResultArrayStatus(const char* name)
    { return this->GetObjectArrayStatus(FACE_SET, name); }
  void SetFaceSetResultArrayStatus(const char* name, int flag)
    { this->SetObjectArrayStatus(FACE_SET, name, flag); }
  
  int GetNumberOfElementSetResultArrays()
    { return this->GetNumberOfObjectArrays(ELEM_SET); }
  const char* GetElementSetResultArrayName(int index)
    { return this->GetObjectArrayName(ELEM_SET, index); }
  int GetElementSetResultArrayStatus(const char* name)
    { return this->GetObjectArrayStatus(ELEM_SET, name); }
  void SetElementSetResultArrayStatus(const char* name, int flag)
    { this->SetObjectArrayStatus(ELEM_SET, name, flag); }

  /**!\brief Fast path 
    *
    * The following are set using the fast-path keys found in 
    * vtkPExodusIIReader's input information. 
    * Fast-path keys are meant to be used by an filter that 
    * works with temporal data. Rather than re-executing the pipeline
    * for each timestep, since the exodus reader, as part of its API, contains
    * a faster way to read temporal data, algorithms may use these
    * keys to request temporal data.
    * See also: vtkExtractArraysOverTime. 
    */
  //@{
  // Description:
  // Set the fast-path keys. All three must be set for the fast-path
  // option to work.
  // Possible argument values: "POINT","CELL","EDGE","FACE"
  void SetFastPathObjectType(const char *type);
  // Description:
  // Possible argument values: "INDEX","GLOBAL"
  // "GLOBAL" means the id refers to a global id
  // "INDEX" means the id refers to an index into the VTK array
  void SetFastPathIdType(const char *type);
  void SetFastPathObjectId(vtkIdType id);
  //@}

  // Description:
  // Reset the user-specified parameters and flush internal arrays
  // so that the reader state is just as it was after the reader was
  // instantiated.
  //
  // It doesn't make sense to let users reset only the internal state;
  // both the settings and the state are changed by this call.
  void Reset();

  // Description:
  // Reset the user-specified parameters to their default values.
  // The only settings not affected are the filename and/or pattern
  // because these have no default.
  //
  // Resetting the settings but not the state allows users to
  // keep the active cache but return to initial array selections, etc.
  void ResetSettings();

  // Description:
  // Clears out the cache entries.
  void ResetCache();

  // Description:
  // Set the size of the cache in MiB.
  void SetCacheSize(double CacheSize);

  // Description:
  // Get the size of the cache in MiB.
  double GetCacheSize();

  // Description:
  // Re-reads time information from the exodus file and updates
  // TimeStepRange accordingly.
  virtual void UpdateTimeInformation();

  virtual void Dump();

  // Description:
  // SIL describes organization of/relationships between classifications 
  // eg. blocks/materials/hierarchies.
  vtkGraph* GetSIL();

  // Description:
  // Every time the SIL is updated a this will return a different value.
  vtkGetMacro(SILUpdateStamp, int);

  // Description:
  // HACK: Used by vtkPExodusIIReader to tell is the reader produced a valid
  // fast path output.
  vtkGetMacro(ProducedFastPathOutput, bool);

protected:
  vtkExodusIIReader();
  ~vtkExodusIIReader();

  // Description:
  // Reset or create an ExodusModel and turn on arrays that must be present for the ExodusIIWriter
  virtual void NewExodusModel();

  // helper for finding IDs
  static int GetIDHelper ( const char *arrayName, vtkDataSet *data, int localID, int searchType );
  static int GetGlobalID( const char *arrayName, vtkDataSet *data, int localID, int searchType );

  virtual void SetMetadata( vtkExodusIIReaderPrivate* );
  vtkGetObjectMacro(Metadata,vtkExodusIIReaderPrivate);

  // Description: 
  // Returns true if XMLFileName has already been set. Otherwise, look for the XML
  // metadata file in the same directory as the data file(s) using the following
  // possible file names:
  //     DATA_FILE_NAME.xml
  //     DATA_FILE_NAME.dart
  //     artifact.dta
  //  Return true if found, false otherwise
  bool FindXMLFile();

  // Time query function. Called by ExecuteInformation().
  // Fills the TimestepValues array.
  void GetAllTimes(vtkInformationVector*); 

  // Description:
  // Populates the TIME_STEPS and TIME_RANGE keys based on file metadata.
  void AdvertiseTimeSteps( vtkInformation* outputInfo );

  virtual void SetExodusModel( vtkExodusModel* em );

  int ProcessRequest( vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  int RequestInformation( vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  int RequestData( vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  //int RequestDataOverTime( vtkInformation *, vtkInformationVector **, vtkInformationVector *);

  // Parameters for controlling what is read in.
  char* FileName;
  char* XMLFileName;
  int TimeStep;
  int TimeStepRange[2];
  vtkTimeStamp FileNameMTime;
  vtkTimeStamp XMLFileNameMTime;
  
  // Information specific for exodus files.

  //1=display Block names
  //2=display Part names
  //3=display Material names
  int DisplayType;
 
  // Metadata containing a description of the currently open file.
  vtkExodusIIReaderPrivate* Metadata;

  vtkExodusModel *ExodusModel;
  int PackExodusModelOntoOutput;
  int ExodusModelMetadata;

  int SILUpdateStamp;
  bool ProducedFastPathOutput;
private:
  vtkExodusIIReader(const vtkExodusIIReader&); // Not implemented
  void operator=(const vtkExodusIIReader&); // Not implemented

  void AddDisplacements(vtkUnstructuredGrid* output);
};

#endif
