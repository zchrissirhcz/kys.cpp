add_executable(kys
  kys.cpp
  Engine.cpp
  TitleScene.cpp
  Application.cpp
)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(kys PRIVATE
  $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
  $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(kys PRIVATE
  $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)

find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(kys PRIVATE
  $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
)

target_link_libraries(kys PRIVATE
  fmt::fmt
  mlcc
)
target_include_directories(kys PUBLIC
  ${CMAKE_SOURCE_DIR}/src
)