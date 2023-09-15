import { Injectable, UseGuards } from '@nestjs/common';
import { CreateUserDto } from './dto/create-user.dto';
import { UpdateUserDto } from './dto/update-user.dto';
import { InjectModel } from '@nestjs/mongoose';
import { User } from 'src/schemas/user.schema';
import { Model } from 'mongoose';
import { AuthGuard } from 'src/auth/auth.guard';

@Injectable()
export class UsersService {
  constructor(@InjectModel(User.name) private userModel: Model<User>) {}

  create(createUserDto: CreateUserDto) {
    const createdUser = new this.userModel(createUserDto);

    return createdUser.save();
  }

  @UseGuards(AuthGuard)
  async findAll() {
    const users = await this.userModel.find().exec();
    return { users: users };
  }

  @UseGuards(AuthGuard)
  findOne(_username: string) {
    return this.userModel.findOne({ username: _username }).exec();
  }

  @UseGuards(AuthGuard)
  async update(username: string, updateUserDto: UpdateUserDto): Promise<User> {
    const updatedUser = await this.userModel.findByIdAndUpdate(
      username,
      updateUserDto,
      {
        new: true,
      },
    );
    return updatedUser;
  }

  @UseGuards(AuthGuard)
  remove(_username: string) {
    return this.userModel.deleteOne({ username: _username });
  }
}
