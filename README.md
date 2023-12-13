# 42_Cub3d

This readme will be divided into two parts. The first part is about simple introduction of the project, aka the installation, compilation, instructions to play the game, and parameters to parse into the program. The second part will dive deep into the algorithms used.

## (Part 1) Introduction of the project
### About
Cub3D is a dynamic first-person view game that utilizes ray-casting techniques.This is a simple game project inspired by Wolfenstein 3D.

---
### Run the program 
```
./cub3d maps/valid.cub
```
The map that parse into the program must end with  `.cub`

---
### Map file requirements
The map that parse into the program must end with  `.cub`

The `NO` is followed by the image use in north walls. This same goes with `SO`(South), `WE`(West), `EA`(East), and `DO`(Door).

`F` is followed by the RBG value for the **floor**. `C` is meant for **ceiling**.

The map can only be composed of these 6 characters:
| charachers   |                                             |
|:------------:|:--------------------------------------------|
| `0`          | an empty space                              |
| `1`          | a wall                                      |
| `N`          | the player's starting position facing north |
| `E`          | the player's starting position facing east  |
| `W`          | the player's starting position facing west  |
| `S`          | the player's starting position facing south |
The map must be closed by walls.
---
### Controls
| characters   |                      |
|:------------:|:---------------------|
| `W`          | Move forward         |
| `S`          | Move backward        |
| `A`          | Move left            |
| `D`          | Move Right           |
| `left arrow` | Rotate left          |
| `right aarow`| Rotate right         |

---
### 
## (Part 2) Algorithms used in this project
### Vector Basic
Math on graphic projects heavily rely on vector and trigonometry. So, in order to have a better understand of the logic behind each algorithms, having the solid foundation of vector and trigonometer is a must.

***Vector***
Vector in Math consist of two components. Every line vector equations are position vector and scaling multiplication of direction vector.

1. position vector
    - One of the points in the line. In math, it can be any point on the line. - 
    - In this project, we'll be using player's coordinates in the map as position vector.
2. direction vector
    - The "direction" of a vector is the angle made by the vector with the horizontal axis, that is, the X-axis.
3. Scalar multiplication
    - Another point on the map is the position vector plus the scalar multiplication of the direction vector.
    - Let use our project as example to explain this. Initially, our player is standing at (2, 4) at facing north. In order to the player to move forward (or backward or sideward), the player need to minus n in y-axis. This n is depend on how much the player want to move toward north. If 10 steps, then 10 x (direction vector toward North), or if 2 steps per time, then it will be 2 x (direction vector toward North). The 2 and 10 here is the scalar multiplication of direction vector. 
    - If you still couldn't understand, recall the transformation you have learned in high school, it's basically the same thing.

### DDA Algorithm

---
### Fix Fisheye Effects
The fisheye effect is fixed by 
```C
ray->perpwalldist *= cos(ray->raydirx - data->player->dirx);

```

---
### Print images on walls

The function (draw_texture) is responsible for drawing the texture on the wall by iterating over each pixel on the wall and mapping it to a corresponding pixel in the texture image. The color of the texture pixel is then retrieved and used to draw the pixel on the screen, creating the visual effect of a textured wall. The calculate_wall_hit function determines where on the wall the ray intersects, and this information is crucial for mapping the texture onto the wall accurately.




| Variables | Purpose |
|-----------|---------|
| draw.x, draw.y | the current pixel position on the screen where the texture is start to draw |
| wall_hit       | the position on the wall where ray is hitting (normalized between 0 and 1) |
| wall_index     | the index of the pixel in the texture image that correspont to the current position on the wall |
| wall.x, wall.y         | the coordinates in the texture image where to get pixel colour | 

To calculate wall_hit
```C
if (ray->side == 0) //the wall is hitting vertical walls (west or east)
    wall_hit = player->py + ray->perpwalldist * ray->diry;
else
    wall_hit = playe->px + ray->perpwalldist * ray->dirx;
wall_hit -= floor(wall_hit); //normalize it to start from 0 
```

Now we can get into a loop that start from drawstart to drawend after we set the initial draw.x and draw.y
```C
draw.x = x // x is current x coordinate on the window (also what we pass in as parameter)
draw.y = ray->drawrstart -1;
while (++draw.y <= ray->drawend)
{
    // codes that calculate wall.x, wall.y, wall_index and dest
}
```

**High overview of what this function does:**
- Iterate over each pixel vertically from the top (draw.y starts just above the top of the wall and increments until just below the bottom of the wall).
- Calculate the texture coordinates (wall.x and wall.y) based on the current pixel's position relative to the wall and the dimensions of the texture.
- Calculate the index of the pixel in the texture image (wall_index).
- Fetch the color of the pixel from the texture image (data->current_texture->addr) and assign it to cub->color.
- Draw the pixel by its colour

```C
wall.x = (int)(wall_hit * data->current_texture->width);
wall.y = (int)(((double)((draw.y - data->ray->drawstart)) / (double)data->ray->lineheight) \
                * data->current_texture->width);
wall_index = wall.x * (data->current_texture->bpp / 8) + wall.y * data->current_texture->line_length;
dest = data->current_texture->addr + wall_index;
my_mlx_pixel_put(data, SIZE_X - draw.x, draw.y, *(unsigned int*)dest);
```

---
### Contributors
- [ziqiqiiii](https://github.com/ziqiqiiii)
- [Ry4nnnn](https://github.com/Ry4nnnn)