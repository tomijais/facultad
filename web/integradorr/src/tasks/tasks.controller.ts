import {
  Controller,
  Get,
  Post,
  Put,
  Delete,
  Body,
  Param,
  Render,
  UseGuards,
} from '@nestjs/common';
import { TasksService } from './tasks.service';
import { Task } from 'src/schemas/task.schema';
import { AuthGuard } from 'src/auth/auth.guard';

@Controller('tasks')
export class TasksController {
  constructor(private readonly taskService: TasksService) {}

  @Get()
  @Render('tasks')
  async getAllTasks(): Promise<{ tasks: Task[] }> {
    const tasks = await this.taskService.getAllTasks();
    return { tasks };
  }

  @Get('create')
  @Render('createTask')
  async create() {
    return {};
  }

  @Get('update/:id')
  @Render('updateTask')
  async update(@Param('id') id: string) {
    return { task: await this.taskService.getTaskById(id) };
  }

  @UseGuards(AuthGuard)
  @Post()
  @Render('tasks')
  async createTask(@Body() task: Task): Promise<{ tasks: Task[] }> {
    await this.taskService.createTask(task);
    const tasks = await this.taskService.getAllTasks();
    return { tasks };
  }

  @UseGuards(AuthGuard)
  @Post('update/:id')
  @Render('tasks')
  async updateTask(
    @Param('id') id: string,
    @Body() task: Task,
  ): Promise<{ tasks: Task[] }> {
    await this.taskService.updateTask(id, task);

    const tasks = await this.taskService.getAllTasks();

    return { tasks };
  }

  @UseGuards(AuthGuard)
  @Post('delete/:id')
  @Render('tasks')
  async deleteTask(@Param('id') id: string): Promise<{ tasks: Task[] }> {
    console.log('pimba');

    await this.taskService.deleteTask(id);

    const tasks = await this.taskService.getAllTasks();

    return { tasks };
  }
}
