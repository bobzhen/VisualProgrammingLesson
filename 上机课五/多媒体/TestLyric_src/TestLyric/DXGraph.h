//
// CDXGraph.h
//

#ifndef __H_CDXGraph__
#define __H_CDXGraph__

// Filter graph notification to the specified window
#define WM_GRAPHNOTIFY  (WM_USER+20)

class CDXGraph
{
private:
	IGraphBuilder *     mGraph;  
	IMediaControl *		mMediaControl;
	IMediaEventEx *		mEvent;
	IBasicVideo *		mBasicVideo;
	IBasicAudio *		mBasicAudio;
	IVideoWindow  *		mVideoWindow;
	IMediaSeeking *		mSeeking;

	DWORD				mObjectTableEntry; 

public:
	CDXGraph();
	virtual ~CDXGraph();

public:
	virtual bool Create(void);
	virtual void Release(void);
	virtual bool Attach(IGraphBuilder * inGraphBuilder);

	IGraphBuilder * GetGraph(void); // Not outstanding reference count
	IMediaEventEx * GetEventHandle(void);

	bool ConnectFilters(IPin * inOutputPin, IPin * inInputPin, const AM_MEDIA_TYPE * inMediaType = 0);
	void DisconnectFilters(IPin * inOutputPin);

	//bool SetDisplayWindow(HWND inWindow);
	bool SetNotifyWindow(HWND inWindow);
	//bool ResizeVideoWindow(long inLeft, long inTop, long inWidth, long inHeight);

	void HandleEvent(WPARAM inWParam, LPARAM inLParam);

	bool Run(void);        // Control filter graph
	bool Stop(void);
	bool Pause(void);
	bool IsRunning(void);  // Filter graph status
	bool IsStopped(void);
	bool IsPaused(void);

	//bool SetFullScreen(BOOL inEnabled);
	//bool GetFullScreen(void);

	// IMediaSeeking
	bool GetCurrentPosition(LONGLONG * outPosition); //获得当前播放时间(单位为100纳秒, 等于10^(-4) ms )
	bool GetStopPosition(LONGLONG * outPosition);
	bool SetCurrentPosition(LONGLONG inPosition); //设置当前播放时间(单位为100纳秒, 等于10^(-4) ms )
	bool SetStartStopPosition(LONGLONG inStart, LONGLONG inStop);
	bool GetDuration(LONGLONG * outDuration); //获得文件时间长度(单位为100纳秒, 等于10^(-4) ms )
	bool SetPlaybackRate(double inRate); //设置播放速度

	// Attention: range from -10000 to 0, and 0 is FULL_VOLUME.
	bool SetAudioVolume(long inVolume);//调节音量
	long GetAudioVolume(void);
	// Attention: range from -10000(left) to 10000(right), and 0 is both.
	bool SetAudioBalance(long inBalance);
	long GetAudioBalance(void);

	bool RenderFile(const char * inFile);


private:
	void AddToObjectTable(void) ;
	void RemoveFromObjectTable(void);
	
	bool QueryInterfaces(void);
};

#endif // __H_CDXGraph__