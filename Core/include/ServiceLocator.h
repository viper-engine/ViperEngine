#ifndef SERVICE_LOCATOR_HEADER
#define SERVICE_LOCATOR_HEADER

#include "Singleton.h"

namespace Viper
{
	class Logger;
	class MemoryAllocator;
	class AudioManager;

	/** This is a singleton class which keeps a handle to all the services
	*  Services should be provided to this class throught the provide method
	*  There are accessor methods for getting individual services
	*/
	class ServiceLocator : Singleton<ServiceLocator>
	{
		friend Singleton<ServiceLocator>;

		Logger* logger;
		MemoryAllocator* memoryAllocator;
		AudioManager* audioManager;

		ServiceLocator();
	public:

		/** Provide a logger implementation to the service locator
		*  @param logger A Logger interface implementation
		*/
		void Provide(Logger* logger);

		/** Provide a memory allocator implementation to the service locator
		*  @param memoryAllocator A MemoryAllocator interface implementation
		*/
		void Provide(MemoryAllocator* memoryAllocator);

		/** Provide an audio manager implementation to the service locator
		*  @param audioManager An AudioManager interface implementation
		*/
		void Provide(AudioManager* audioManager);

		/** Gets a reference to the default Logger
		*  @return A referece to the default logger
		*/
		static Logger& GetLogger();

		/** Gets a reference to the default memory allocator
		*  @return A referece to the default memory allocator
		*/
		static MemoryAllocator& GetMemoryAllocator();

		/** Gets a reference to the default AudioManager
		*  @return A referece to the default AudioManager
		*/
		static AudioManager& GetAudioManager();
	};
}

#endif // SERVICE_LOCATOR_HEADER
