function(add_testing_sources target sources)
    if(DEFINED CMAKE_TESTING_ENABLED)
        target_sources(${target} PRIVATE ${sources})
    endif()
endfunction()